/*
 * File:   RF_RFM95W.c
 * Author: Claudio Monteiro
 *
 * Created on August 6th 2018, 12:00
 */



#include "RF_RFM95W.h"
#include "UART.h"
#include "delay.h"


volatile RF_STRUCT rf;          /* Struct with the header (ordid, msgid, net, sn), payload, ttl and cks */
volatile RF_STRUCT *rfPt;       /* Pointer for the handling of the struct*/



uint8_t tmpBuff[RF_BUFF_LEN];             /* Temp Buffer to get and send the message */

//uint8_t tx_test[50];
//uint8_t i;

/**
 * Function to write 1 Register of 1 Byte
 */
__attribute__((mips16)) void RF_RFM95W_WrtReg(uint8_t reg, uint8_t data)
{
    CS_RF_ON;

    SPI1_transfer(reg | 0x80);      /* Set the MSb to write to a register */
    SPI1_transfer(data);

    CS_RF_OFF;
}


/**
 * Function to write 1 array of x bytes
 */
__attribute__((mips16)) void RF_RFM95W_WrtArray(uint8_t reg, uint8_t *array, uint8_t arraySize)
{
    uint8_t i;

    CS_RF_ON;

    SPI1_transfer(reg | 0x80);      /* Set the MSb to write to a register */

    /* Write 1 byte at a time from the array */
    for(i=0; i<arraySize; i++)
    {
        SPI1_transfer(array[i]);
    }

    CS_RF_OFF;
}


/**
 * Function to read 1 Register of 1 Byte
 */
__attribute__((mips16)) uint8_t RF_RFM95W_ReadReg(uint8_t reg)
{
    uint8_t readByte;

    CS_RF_ON;

    SPI1_transfer(reg);                 /* No change to the register */
    readByte = SPI1_transfer(0x00);     /* Send dummy byte to receive status register */

    CS_RF_OFF;

    return readByte;
}


/**
 * Function to read 1 array of x bytes
 */
__attribute__((mips16)) void RF_RFM95W_ReadArray(uint8_t reg, uint8_t *array, uint8_t arraySize)
{
    uint8_t i;

    CS_RF_ON;

    SPI1_transfer(reg);                /* Send the register to initiate array read */

    /* Request and store the array for the length  */
    for(i=0; i<arraySize; i++)
    {
        array[i] = SPI1_transfer(0x00);      /*Send dummy byte to read 1 byte*/
    }

    CS_RF_OFF;
}


/**
 * Function to clear RF Interrupts
 */
__attribute__((mips16)) void RF_RFM95W_ClrRfInt(void)
{
    RF_RFM95W_WrtReg(RF_REG_IRQ_FLAGS, 0xFF);   /* Wrintig clears the flags */
}


/**
 * Function to clear RF FIFO
 */
__attribute__((mips16)) void RF_RFM95W_ClrFIFO(void)
{
    /* Change to RxMode from StandbyMode, can clear FIFO buffer */
    RF_RFM95W_WrtReg(RF_REG_OPMODE, 0x80);       /* Sleep mode clears FIFO */
    RF_RFM95W_StandbyMode();
}


/**
 * Function to Initialise the RF Module
 */
__attribute__((mips16)) void RF_RFM95W_Init(void)
{
    /* Configure and initialise RF interrupt pin */
    ConfigINT0(EXT_INT_PRI_7 | RISING_EDGE_INT | EXT_INT_ENABLE);
    SetSubPriorityINT0(EXT_INT_SUB_PRI_1);
    mINT0ClearIntFlag();
    
    rfPt = &rf;
    memset(rfPt, 0x00, sizeof(RF_STRUCT));     
}


/**
 * Function to Initialise the RF module
 */
__attribute__((mips16)) void RF_RFM95W_Config(void)
{   

    RF_RFM95W_WrtReg(RF_REG_OPMODE, 0x00);          // Set sleep mode and clears FIFO
    delayMs(10);
    RF_RFM95W_WrtReg(RF_REG_OPMODE, 0x80);          // Set LoRa mode
    delayMs(10);
       
    /* Configuration of the RF Frequency */
    if (rf.freq == RF_868)
    {
        RF_RFM95W_WrtReg(RF_REG_FRFMSB, 0xD9);
        RF_RFM95W_WrtReg(RF_REG_FRFMID, 0x00);
        RF_RFM95W_WrtReg(RF_REG_FRFLSB, 0x00); 
    }
    else if (rf.freq == RF_918)
    {
        RF_RFM95W_WrtReg(RF_REG_FRFMSB, 0xE5);
        RF_RFM95W_WrtReg(RF_REG_FRFMID, 0x80);
        RF_RFM95W_WrtReg(RF_REG_FRFLSB, 0x00);
    }
     
    RF_RFM95W_WrtReg(RF_REG_PALEVEL, 0xFF);         // PA boost on     
    RF_RFM95W_WrtReg(RF_REG_PARAMP, 0x07);          // PA ramp 62 us
    RF_RFM95W_WrtReg(RF_REG_OCP, 0x37);             // Overcurrent protection on = 200 mA
    RF_RFM95W_WrtReg(RF_REG_LNA, 0x00);             // LNA gain off, LNA boost off
    RF_RFM95W_WrtReg(RF_REG_IRQ_FLAGS_MASKS, 0x07); // Unmasks interrupts
    
    RF_RFM95W_WrtReg(RF_REG_MODEM_CONF_1, 0x72);    // Modem configuration
    RF_RFM95W_WrtReg(RF_REG_MODEM_CONF_2, 0x74);    // Modem configuration
    RF_RFM95W_WrtReg(RF_REG_MODEM_CONF_3, 0x04);    // Modem configuration - AGC auto on
    
    RF_RFM95W_WrtReg(RF_REG_FIFO_TX_ADDR, 0x80);
    RF_RFM95W_WrtReg(RF_REG_FIFO_RX_ADDR, 0x00); 
    RF_RFM95W_WrtReg(RF_REG_FIFO_ADDR_PTR, 0x00);  
            
    RF_RFM95W_WrtReg(RF_REG_SYMBOL_TO, 0x64);       // Sumbol timeout 
    RF_RFM95W_WrtReg(RF_REG_PREAMBLEMSB, 0x00);     // Set Preamble Size to 8 Bytes 
    RF_RFM95W_WrtReg(RF_REG_PREAMBLELSB, 0x08);
    RF_RFM95W_WrtReg(RF_REG_SYNC_WORD, 0x34);
    RF_RFM95W_WrtReg(RF_REG_DETECTION_OPT, 0xC3);
    //RF_RFM95W_WrtReg(RF_REG_LORA_INVERT_IQ, (RF_RFM95W_ReadReg(RF_REG_LORA_INVERT_IQ) | 0x40)); // Invert I and Q
    RF_RFM95W_WrtReg(RF_REG_LORA_INVERT_IQ, (RF_RFM95W_ReadReg(RF_REG_LORA_INVERT_IQ) & 0xBF)); // Normal mode
    RF_RFM95W_WrtReg(RF_REG_DETECTION_THSD, 0x0A);
    RF_RFM95W_WrtReg(RF_REG_MAX_PAYLOAD_LEN, 0xFF); // Max payload len
    RF_RFM95W_WrtReg(RF_REG_TCXO, 0x09);            // OSC = XTAL
    RF_RFM95W_WrtReg(RF_REG_PA_DAC, 0x84);          // PA = defaul maximum level at PA=0b1111
    RF_RFM95W_WrtReg(RF_REG_PLL_HF, 0xD0);          // PLL = 300kHz
    
    RF_RFM95W_WrtReg(RF_REG_DIOMAPPING1, 0x3F);     // DIO mapped RX=0x3F, TX=0x7F
    RF_RFM95W_WrtReg(RF_REG_DIOMAPPING2, 0xF1); 
    
    RF_RFM95W_ClrFIFO();
    RF_RFM95W_RxMode();
    
    /* Wait Cycle */
    delayMs(5);     
}


/**
 * Function to set the RF module to Standby MODE
 */
__attribute__((mips16)) void RF_RFM95W_StandbyMode(void)
{
    RF_RFM95W_WrtReg(RF_REG_OPMODE, 0x81);              /* Enters Standby Mode */          
}


/**
 * Function to set the RF module to FS (Frequency Synthesizer) MODE
 */
__attribute__((mips16)) void RF_RFM95W_FSMode(void)
{
    //RF_RFM95W_WrtReg(RF_REG_OPMODE, 0x88);            /* Enters Frequency Synthesizer Mode */    
}


/**
 * Function to set the RF module to RX MODE
 */
__attribute__((mips16)) void RF_RFM95W_RxMode(void)
{
    //RF_RFM95W_StandbyMode();
    RF_RFM95W_ClrFIFO(); 
    RF_RFM95W_ClrRfInt();
    RF_RFM95W_WrtReg(RF_REG_DIOMAPPING1, 0x3F);       /* Map DIO0 to RX done */
    RF_RFM95W_WrtReg(RF_REG_OPMODE, 0x85);            /* Enter RX continous mode */    
}


/**
 * Function to set the RF module to TX MODE
 */
__attribute__((mips16)) void RF_RFM95W_TxMode(void)
{
    RF_RFM95W_ClrRfInt();
    RF_RFM95W_WrtReg(RF_REG_DIOMAPPING1, 0x7F);       /* Map DIO0 to TX done */
    RF_RFM95W_WrtReg(RF_REG_OPMODE, 0x83);            /* Enter TX Mode */    
}


/**
 * Function to write in the tx fifo and start to transmit according to Sensing RF protocol
 * 
 * This function only have the expected behaviour if the RF module is in Standby Mode
 */
__attribute__((mips16)) void RF_RFM95W_WrtTXfifo(uint8_t *msg, uint8_t len)
{   
    memcpy(tmpBuff, msg, len);
    
    RF_RFM95W_StandbyMode();
                  
    /* Write message to FIFO */
    RF_RFM95W_WrtReg(RF_REG_FIFO_ADDR_PTR, RF_RFM95W_ReadReg(RF_REG_FIFO_TX_ADDR));  //Set FIFO pointer to TX base address
    RF_RFM95W_WrtReg(RF_REG_PAYLOAD_LEN, len);     //Used in implicit mode only
    RF_RFM95W_WrtArray(RF_REG_FIFO, tmpBuff, len);    
          
    /* Enter TX Mode and start transmitting */
    RF_RFM95W_TxMode();  
}


/**
 * Function to Get received RF messages
 */
__attribute__((mips16))  void RF_RFM95W_ReadRXfifo(uint8_t *msg, uint8_t *len)
{    
    /* Change RF-State to Standby mode */
    RF_RFM95W_StandbyMode(); 
    
    *len = RF_RFM95W_ReadReg(RF_REG_RX_NB_BYTES);
       
    RF_RFM95W_WrtReg(RF_REG_FIFO_ADDR_PTR, RF_RFM95W_ReadReg(RF_REG_FIFO_CURR_ADDR));  //Set FIFO pointer to last packet address

    /* Read the Address Byte and then the message */
    RF_RFM95W_ReadArray(RF_REG_FIFO, msg, *len);    /* read FIFO */   
}


__attribute__((mips16)) uint8_t RF_RFM95W_GetRSSI(void)
{
    //return RF_RFM95W_ReadReg(RF_REG_RSSI);
}


/**
 * Function to get the status
 */
__attribute__((mips16)) uint8_t RF_RFM95W_GetDevStt(void)
{
    return RF_RFM95W_ReadReg(RF_REG_MODEM_STATUS);
}


/**
 * Function to Change RF State
 */
__attribute__((mips16)) void RF_RFM95W_ChgStt(void)
{
    /* Change to RxMode from StandbyMode, to restart RX mode */
    RF_RFM95W_StandbyMode();
    
    /* Wait Cycle */
    delayMs(1);
    
    RF_RFM95W_RxMode();

    /* Wait Cycle */
    delayMs(1);    
}
