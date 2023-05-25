/* 
 * File:   RF_RFM22B.h
 * Author: André Gomes
 *
 * Created on 4 de Fevereiro de 2013, 17:24
 */

#ifndef RF_RFM22B_H
#define	RF_RFM22B_H

#include <plib.h>
#include <stdint.h>

#include "SPI.h"
#include "M1_RF.h"


#define RF_BUFF_LEN         (64)

#define CS_RF_ON            LATBbits.LATB4=0 /*mPORTBSetBits(BIT_4)*/
#define CS_RF_OFF           LATBbits.LATB4=1 /*mPORTBClearBits(BIT_4)*/


/******************************************************************************/
/* Registers for the RF module config                                         */
/******************************************************************************/
#define RF_REG_DEVTYPE          0x00
#define RF_REG_DEVVER           0x01
#define RF_REG_DEVSTT           0x02
#define RF_REG_INTSTT1          0x03
#define RF_REG_INTSTT2          0x04
#define RF_REG_INTENABLE1       0x05		//RX interrupt
#define RF_REG_INTENABLE2       0x06
#define RF_REG_OP_MODE1         0x07		//Config RX Mode, TX Mode or Ready Mode
#define RF_REG_OP_MODE2         0x08            //Antenna diversity | Fifo RX Clear | Fifo TX Clear
#define RF_REG_OSCCONF          0x09
#define RF_REG_GPIO0CONF        0x0B
#define RF_REG_GPIO1CONF        0x0C
#define RF_REG_PORTCONF         0x0E		//Port configurations
#define RF_REG_ADCCONF1         0x0F
#define RF_REG_ADCCONF2         0x10
#define RF_REG_TEMPCONF1        0x12
#define RF_REG_TEMPCONF2        0x13
#define RF_REG_IF_FILTCONF      0x1C
#define RF_REG_AFCCONF          0x1D
#define RF_REG_CLKRECOVER       0x20
#define RF_REG_CLKCONF2         0x21
#define RF_REG_CLKCONF1         0x22
#define RF_REG_CLKCONF0         0x23
#define RF_REG_CLKRECTG1        0x24
#define RF_REG_CLKRECTG0        0x25
#define RF_REG_RSSI             0x26
#define RF_REG_AFCLIMITER       0x2A
#define RF_REG_DATACONF         0x30
#define RF_REG_EZMACSTT         0x31
#define RF_REG_HEADERCTRL1      0x32
#define RF_REG_HEADERCTRL2      0x33
#define RF_REG_PRELENCONF       0x34
#define RF_REG_PRECTRLCONF      0x35
#define RF_REG_SYNCCONF3        0x36
#define RF_REG_SYNCCONF2        0x37
#define RF_REG_SYNCCONF1        0x38
#define RF_REG_SYNCCONF0        0x39
#define RF_REG_THEADER3         0x3A
#define RF_REG_THEADER2         0x3B
#define RF_REG_THEADER1         0x3C
#define RF_REG_THEADER0         0x3D
#define RF_REG_TXPKTLEN         0x3E
#define RF_REG_CHKHEADER3       0x3F
#define RF_REG_CHKHEADER2       0x40
#define RF_REG_CHKHEADER1       0x41
#define RF_REG_CHKHEADER0       0x42
#define RF_REG_HEADEREN3        0x43
#define RF_REG_HEADEREN2        0x44
#define RF_REG_HEADEREN1        0x45
#define RF_REG_HEADEREN0        0x46
#define RF_REG_RXPKTLEN         0x4B
#define RF_REG_TXPOWER          0x6D
#define RF_REG_TXBAUDRATE1      0x6E
#define RF_REG_TXBAUDRATE0      0x6F
#define RF_REG_MODCONF1         0x70
#define RF_REG_MODCONF2         0x71
#define RF_REG_FREQDEV          0x72
#define RF_REG_FREQBAND         0x75
#define RF_REG_FREQCARRIER1     0x76
#define RF_REG_FREQCARRIER0     0x77
#define RF_REG_FIFO             0x7F


typedef struct
{
    RFMSG_STRUCT    rxMsg;
    RFMSG_STRUCT    txMsg;
    uint8_t         int_RF;
    uint8_t         msgRcv;
    uint8_t         msgSent;
    uint8_t         msgIDsend;
    uint8_t         cnt5s;
    uint8_t         rssiVal;
    uint8_t         freq;

}RF_STRUCT;


/**
 * Function to write 1 Register of 1 Byte
 */
__attribute__((mips16)) void RF_RFM22B_WrtReg(uint8_t reg, uint8_t data);


/**
 * Function to write 1 array of x bytes
 */
__attribute__((mips16)) void RF_RFM22B_WrtArray(uint8_t reg, uint8_t *array, uint8_t arraySize);


/**
 * Function to read 1 Register of 1 Byte
 */
__attribute__((mips16)) uint8_t RF_RFM22B_ReadReg(uint8_t reg);


/**
 * Function to read 1 array of x bytes
 */
__attribute__((mips16)) void RF_RFM22B_ReadArray(uint8_t reg, uint8_t *array, uint8_t arraySize);


/**
 * Function to clear RF Interrupts
 */
__attribute__((mips16)) void RF_RFM22B_ClrRfInt(void);


/**
 * Function to Initialize the RF Module
 */
__attribute__((mips16)) void RF_RFM22B_Init(void);


/**
 * Function to Configure the RF Module
 */
__attribute__((mips16)) void RF_RFM22B_Config(void);


/**
 * Function to set the RF module to RX MODE
 */
__attribute__((mips16)) void RF_RFM22B_RxMode(void);


/**
 * Function to set the RF module to READY MODE
 */
__attribute__((mips16)) void RF_RFM22B_ReadyMode(void);


/**
 * Function to enable RX interrupts
 */
__attribute__((mips16)) void RF_RFM22B_EnRfInt(void);


/**
 * Function to Disable RX interrupts
 */
__attribute__((mips16)) void RF_RFM22B_DisRfInt(void);


/**
 * Function to write in the tx fifo and start to transmit
 */
__attribute__((mips16)) void RF_RFM22B_WrtTXfifo(uint8_t *msg, uint8_t len);


/**
 * Function to Get received RF messages
 */
__attribute__((mips16)) uint8_t RF_RFM22B_ReadRXfifo(uint8_t *msg, uint8_t *len);


__attribute__((mips16)) uint8_t RF_RFM22B_GetRSSI(void);


/**
 * Function to clear the RF buffer
 */
__attribute__((mips16)) void RF_RFM22B_ClrMsg(RFMSG_STRUCT *msg);


/**
 * Function to calculate the checksum of buffer of x bytes
 */
__attribute__((mips16)) uint8_t RF_RFM22B_CksCalc(RFMSG_STRUCT *msg);


/**
 * Function to get the status
 */
__attribute__((mips16)) uint8_t RF_RFM22B_GetDevStt(void);


/**
 * Function to set the Software Reset
 */
__attribute__((mips16)) void RF_RFM22B_SetSoftRESET(void);


#endif	/* RF_RFM22B_H */

