/*
 * File:   RF_RFM69HCW.c
 * Author: André Gomes
 *
 * Created on 11 de Fevereiro de 2015, 12:00
 */



#include "RF_RFM69HCW.h"
#include "UART.h"
#include "delay.h"


volatile RF_STRUCT rf;          /* Struct with the header (ordid, msgid, net, sn), payload, ttl and cks */
volatile RF_STRUCT *rfPt;       /* Pointer for the handling of the struct*/


uint8_t tmpBuff[RF_BUFF_LEN];             /* Temp Buffer to get and send the message */


/**
 * Function to write 1 Register of 1 Byte
 */
__attribute__((mips16)) void RF_RFM69HCW_WrtReg(uint8_t reg, uint8_t data)
{
    CS_RF_ON;

    SPI1_transfer(reg | 0x80);      /* Set the MSb to write to a register */
    SPI1_transfer(data);

    CS_RF_OFF;
}


/**
 * Function to write 1 array of x bytes
 */
__attribute__((mips16)) void RF_RFM69HCW_WrtArray(uint8_t reg, uint8_t *array, uint8_t arraySize)
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
__attribute__((mips16)) uint8_t RF_RFM69HCW_ReadReg(uint8_t reg)
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
__attribute__((mips16)) void RF_RFM69HCW_ReadArray(uint8_t reg, uint8_t *array, uint8_t arraySize)
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
__attribute__((mips16)) void RF_RFM69HCW_ClrRfInt(void)
{
    /* In this RF module the interrupts are not cleared by reading the register
     * These register readings are to ensure a proper RF processing */
    RF_RFM69HCW_ReadReg(RF_REG_IRQFLAGS1);
    RF_RFM69HCW_ReadReg(RF_REG_IRQFLAGS2);
}


/**
 * Function to clear RF FIFO
 */
__attribute__((mips16)) void RF_RFM69HCW_ClrFIFO(void)
{
    /* Change to RxMode from StandbyMode, can clear FIFO buffer */
    RF_RFM69HCW_WrtReg(RF_REG_OPMODE, 0x04);       /* Standby Mode */
    RF_RFM69HCW_WrtReg(RF_REG_OPMODE, 0x10);       /* RX Mode */    
}


/**
 * Function to Initialise the RF Module
 */
__attribute__((mips16)) void RF_RFM69HCW_Init(void)
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
__attribute__((mips16)) void RF_RFM69HCW_Config(void)
{   

    /* Configuration of the RF Frequency */
     if (rf.freq == RF_868)
    {
        RF_RFM69HCW_WrtReg(RF_REG_FRFMSB, 0xD9);
        RF_RFM69HCW_WrtReg(RF_REG_FRFMID, 0x00);
        RF_RFM69HCW_WrtReg(RF_REG_FRFLSB, 0x00); 
    }
    else if (rf.freq == RF_918)
    {
        RF_RFM69HCW_WrtReg(RF_REG_FRFMSB, 0xE5);
        RF_RFM69HCW_WrtReg(RF_REG_FRFMID, 0x80);
        RF_RFM69HCW_WrtReg(RF_REG_FRFLSB, 0x00);
    }
     
    /* Configuration of the bitrate of the communication - 57.600kbs */
    RF_RFM69HCW_WrtReg(RF_REG_BITRATE_MSB, 0x02);
    RF_RFM69HCW_WrtReg(RF_REG_BITRATE_LSB, 0x2C);
     
    /* Configuration of the General Configurations */
    RF_RFM69HCW_WrtReg(RF_REG_DATAMODUL, 0x00);         /* Packet Mode, FSK, No Shaping */  
    RF_RFM69HCW_WrtReg(RF_REG_FDEV_MSB, 0x08);          /* Frequency deviation set to 135.010 kHz */
    RF_RFM69HCW_WrtReg(RF_REG_FDEV_LSB, 0xA4); 
    RF_RFM69HCW_WrtReg(RF_REG_RXBW, 0x50);              /* RX Bandwidth set to 333.333 KHz, 4% DCC canceller  */
    RF_RFM69HCW_WrtReg(RF_REG_AFCBW, 0x50);             /* RX Bandwidth during AFC - 333.333 KHz, 4% DCC canceller */
    //RF_RFM69HCW_WrtReg(RF_REG_AFCFEI, 0x1C);            /* AFC Auto ON, Auto Clear */
    RF_RFM69HCW_WrtReg(RF_REG_AFCFEI, 0x00);            /* AFC Auto OFF, Auto Clear OFF */
    RF_RFM69HCW_WrtReg(RF_REG_TESTDAGC, 0x30);          /* Fading margin improvement */
    RF_RFM69HCW_WrtReg(RF_REG_RSSITHRESH, 0xFA);        /* RSSI Threshold: -125 dBm */
    RF_RFM69HCW_WrtReg(RF_REG_RXTIMEOUT1, 0x00);        /* Timeout RX-RSSI disable */
    RF_RFM69HCW_WrtReg(RF_REG_RXTIMEOUT2, 0x00);        /* Timeout RSSI-PayLoadReady disable */
    
    /* Set configurations of the RF messages */
    RF_RFM69HCW_WrtReg(RF_REG_PREAMBLEMSB, 0x00);       /* Set Preamble Size to 4 Bytes */
    RF_RFM69HCW_WrtReg(RF_REG_PREAMBLELSB, 0x04);
    RF_RFM69HCW_WrtReg(RF_REG_SYNCCONFIG, 0x98);        /* Sync Word ON, 4 Bytes */
    RF_RFM69HCW_WrtReg(RF_REG_SYNCVALUE1, 0xAA);        /* Sync Word, 0xAAABACAD */
    RF_RFM69HCW_WrtReg(RF_REG_SYNCVALUE2, 0xAB);        
    RF_RFM69HCW_WrtReg(RF_REG_SYNCVALUE3, 0xAC);
    RF_RFM69HCW_WrtReg(RF_REG_SYNCVALUE4, 0xAD);
    RF_RFM69HCW_WrtReg(RF_REG_PACKETCONFIG1, 0xD4);     /* Variable Length, Whitening, CRC ON and Auto Clear, Address filtering Node/Broadcast */
    //RF_RFM69HCW_WrtReg(RF_REG_PACKETCONFIG1, 0xDC);     /* Variable Length, Whitening, CRC ON and NO Auto Clear, Address filtering Node/Broadcast */
    RF_RFM69HCW_WrtReg(RF_REG_PAYLOADLENGTH, 0x40);     /* Set the maximum length */
    RF_RFM69HCW_WrtReg(RF_REG_NODEADRS, 0x5C);          /* Node address - 0x5C */
    RF_RFM69HCW_WrtReg(RF_REG_BROADCASTADRS, 0xC5);     /* Broadcast address - 0xC5 */
    RF_RFM69HCW_WrtReg(RF_REG_FIFOTHRESH, 0x88);        /* Start condition - FifoNotEmpty */
    RF_RFM69HCW_WrtReg(RF_REG_PACKETCONFIG2, 0x32);     /* Auto restart RX, AES OFF - 139us Inter Packet RX Delay */    
    
    /* Set normal Output Power, when in TX mode the Output power will be set to a higher value */
    RF_RFM69HCW_WrtReg(RF_REG_PALEVEL, 0x9F);           /* PA Level set to 13dBm, PA0 in RFIO and LNA */         
    
    RF_RFM69HCW_WrtReg(RF_REG_PARAMP, 0x07);            /* PA Ramp set to 62us */
    RF_RFM69HCW_WrtReg(RF_REG_OCP, 0x0F);               /* Overload Current protection OFF */          
    
    /* Set RX Mode and configure the DIO Pins */
    RF_RFM69HCW_WrtReg(RF_REG_LNA, 0x08);               /* LNA input impedance set to 50ohms, Gain set by the AGC */
    RF_RFM69HCW_WrtReg(RF_REG_TESTLNA, 0x1B);           /* Normal Sensitivity */
    //RF_RFM69HCW_WrtReg(RF_REG_TESTLNA, 0x2D);           /* High Sensitivity mode */
    
    RF_RFM69HCW_WrtReg(RF_REG_DIOMAPPING1, 0x40);       /* Map DIO0 to the Payload Ready Interrupt */
    RF_RFM69HCW_WrtReg(RF_REG_DIOMAPPING2, 0x07);       /* CLKout OFF */    
    RF_RFM69HCW_WrtReg(RF_REG_TESTPA1, 0x55);           /* Normal Mode and RX Mode */
    RF_RFM69HCW_WrtReg(RF_REG_TESTPA2, 0x70);           /* Normal Mode and RX Mode */ 
    RF_RFM69HCW_WrtReg(RF_REG_OPMODE, 0x10);            /* Enter RX Mode */      
    
    /* Clear the RF interrupts to avoid problems*/
    RF_RFM69HCW_ClrRfInt();
    
    /* Wait Cycle */
    delayMs(1);
}


/**
 * Function to set the RF module to Standby MODE
 */
__attribute__((mips16)) void RF_RFM69HCW_StandbyMode(void)
{
    RF_RFM69HCW_WrtReg(RF_REG_OPMODE, 0x04);            /* Enter Standby Mode */    
}


/**
 * Function to set the RF module to FS (Frequency Synthesizer) MODE
 */
__attribute__((mips16)) void RF_RFM69HCW_FSMode(void)
{
    RF_RFM69HCW_WrtReg(RF_REG_OPMODE, 0x08);            /* Enter Frequency Synthesizer Mode */    
}


/**
 * Function to set the RF module to RX MODE
 */
__attribute__((mips16)) void RF_RFM69HCW_RxMode(void)
{
    RF_RFM69HCW_WrtReg(RF_REG_PALEVEL, 0x9F);           /* PA Level set to 13dBm, PA0 in RFIO and LNA */  
    RF_RFM69HCW_WrtReg(RF_REG_DIOMAPPING1, 0x40);       /* Map DIO0 to the Payload Ready Interrupt */
    RF_RFM69HCW_WrtReg(RF_REG_TESTPA1, 0x55);           /* Normal Mode and RX Mode */
    RF_RFM69HCW_WrtReg(RF_REG_TESTPA2, 0x70);           /* Normal Mode and RX Mode */ 
    RF_RFM69HCW_WrtReg(RF_REG_OPMODE, 0x10);            /* Enter RX Mode */
}


/**
 * Function to set the RF module to TX MODE
 */
__attribute__((mips16)) void RF_RFM69HCW_TxMode(void)
{
    RF_RFM69HCW_WrtReg(RF_REG_DIOMAPPING1, 0x00);       	/* Map DIO0 to the Packet Sent Interrupt */
    if (rf.freq == RF_868)
    {
        RF_RFM69HCW_WrtReg(RF_REG_PALEVEL, 0x7F);           /* PA Level set to 20dBm */
        RF_RFM69HCW_WrtReg(RF_REG_TESTPA1, 0x5D);           /* 20dBm Mode */       
        RF_RFM69HCW_WrtReg(RF_REG_TESTPA2, 0x7C);           /* 20dBm Mode */ 
    }
    else if (rf.freq == RF_918)    
    {
        RF_RFM69HCW_WrtReg(RF_REG_PALEVEL, 0x7C);           /* PA Level set to 14dBm */  
        RF_RFM69HCW_WrtReg(RF_REG_TESTPA1, 0x55);           /* Normal Mode */       
        RF_RFM69HCW_WrtReg(RF_REG_TESTPA2, 0x70);           /* Normal Mode */         
    }
 
    RF_RFM69HCW_WrtReg(RF_REG_OPMODE, 0x0C);                /* Enter TX Mode */
}


/**
 * Function to write in the tx fifo and start to transmit according to Sensing RF protocol
 * 
 * This function only have the expected behaviour if the RF module is in Standby Mode
 */
__attribute__((mips16)) void RF_RFM69HCW_WrtTXfifo(uint8_t *msg, uint8_t len)
{   
    /* Write the Length of message (1st Byte) in the FIFO - Node Address + length of message */    
    tmpBuff[0] = len+1;
    tmpBuff[1] = NODE_ADDRESS;
    memcpy(tmpBuff+2, msg, len+1);
        
    /* Write message to FIFO */
    RF_RFM69HCW_WrtArray(RF_REG_FIFO, tmpBuff, len+2);    
    
    /* Enter TX Mode and start transmitting */
    RF_RFM69HCW_TxMode();      
}


/**
 * Function to Get received RF messages
 */
__attribute__((mips16))  void RF_RFM69HCW_ReadRXfifo(uint8_t *msg, uint8_t *len)
{    
    /* Change RF-State to Standby mode */
    RF_RFM69HCW_StandbyMode();     

    *len = (RF_RFM69HCW_ReadReg(RF_REG_FIFO) - 1);                /* Get the number of bytes received minus the Address byte */
 
    /* Read the Address Byte and then the message */
    RF_RFM69HCW_ReadReg(RF_REG_FIFO);    
    RF_RFM69HCW_ReadArray(RF_REG_FIFO, msg, *len);              /* read FIFO */
}


__attribute__((mips16)) uint8_t RF_RFM69HCW_GetRSSI(void)
{
    //return RF_RFM22B_ReadReg(RF_REG_RSSI);
}


/**
 * Function to get the status
 */
__attribute__((mips16)) uint8_t RF_RFM69HCW_GetDevStt(void)
{
    //return RF_RFM22B_ReadReg(RF_REG_DEVSTT);
}


/**
 * Function to Change RF State
 */
__attribute__((mips16)) void RF_RFM69HCW_ChgStt(void)
{
    /* Change to RxMode from StandbyMode, to restart RX mode */
    RF_RFM69HCW_StandbyMode();
    
    /* Wait Cycle */
    delayMs(1);
    
    RF_RFM69HCW_RxMode();

    /* Wait Cycle */
    delayMs(1);    
}
