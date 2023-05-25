/*
 * File:   PW_MCP39F501.c
 * Author: André Gomes
 *
 * Created on 26 de Fevereiro de 2014, 10:34
 */


#include "PM_MCP39F511.h"
#include "UART.h"
#include "user.h"


PM_STRUCT pm;
PM_STRUCT *pmPt;


//uint8_t selectDeviceMsg[]={PM_HEADER, PM_SELDEV_LEN, PM_SELECT_DEV, 0x4C, 0x42};
//uint8_t readValues[]={PM_HEADER, PM_READVALS_LEN, PM_SET_ADD_PT, 0x00, 0x04, PM_READ_N, PM_LINE_FREQ, 0x58};
//uint8_t calibTemp[]={PM_HEADER, PM_CALTEMP_LEN, PM_SET_ADD_PT, 0x00, 0xB6, PM_WRITE16, 0x00, 0x00, 0x00};


uint8_t eraseEEPROMmsg[]={PM_HEADER, 0x05, PM_EEPROM_ERASE, 0x4C, 0x45};


__attribute__((mips16)) void PM_MCP39F501_Init(void)
{  
    /* Set RESET state to initialize the PM */
    RESET_PM_ON;
    delayMs(10);

    /* PM Initialized */
    RESET_PM_OFF;
    delayMs(10); 
}


/**
 * Function to calculate the checksum of buffer of x bytes
 */
__attribute__((mips16)) uint8_t PM_MCP39F501_CksCalc(uint8_t *msg, uint8_t len)
{
    uint8_t i;
    uint16_t cks=0;

    for (i=0; i<len-1; i++)
    {
        cks += *(msg+i);
    }

    cks = (uint8_t)(cks & 0x00FF);

    return cks;
}

