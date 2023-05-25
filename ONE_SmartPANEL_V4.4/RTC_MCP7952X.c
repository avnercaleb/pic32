/*
 * File:   RTC_MCP7952X.c
 * Author: André Gomes
 *
 * Created on 28 de Janeiro de 2013, 17:19
 */

#include "RTC_MCP7952X.h"


/* Struct that will save calendar information */
RTC_DATA rtc;
RTC_DATA *rtcPt;


void RTC_MCP7952x_Init(void)
{
    CS_RTC_ON;
    SPI1_transfer(RTC_OP_WRITE);
    SPI1_transfer(RTC_CTRL_REG);
    SPI1_transfer(0x00);
    CS_RTC_OFF;

    _nop();
    
    CS_RTC_ON;
    SPI1_transfer(RTC_OP_WRITE);
    SPI1_transfer(RTC_CALIB);
    SPI1_transfer(0x00);
    CS_RTC_OFF;

    _nop();

    CS_RTC_ON;

    SPI1_transfer(RTC_OP_SRWRITE);
    SPI1_transfer(0x00);

    CS_RTC_OFF;

    //Initialize RTC struct and pointer
    rtcPt = &rtc;
    memset(rtcPt, 0x00, sizeof(RTC_DATA));
}


__attribute__((mips16)) void RTC_MCP7952x_WrtCalendar(RTC_DATA *data)
{
    CS_RTC_ON;

    SPI1_transfer(RTC_OP_WRITE);    /* Send write operation */
    SPI1_transfer(RTC_Seconds);     /* Select address */

    SPI1_transfer(((data->seconds/10)<<4) | (data->seconds%10) | START_OSC);    /* write seconds to rtc + Start oscillator */
    SPI1_transfer(((data->minutes/10)<<4) | (data->minutes%10));                /* write minutes */
    SPI1_transfer((((data->hours/10)<<4)&0x30) | (data->hours%10));             /* write hours and set 24h mode */

    SPI1_transfer((data->day & 0x07) | VBATEN);                                 /* write day + set VBATEN */
    SPI1_transfer(((data->date/10)<<4) | (data->date%10));                      /* write date */
    SPI1_transfer(((data->month/10)<<4) | (data->month%10));                    /* write month */
    SPI1_transfer(((data->year/10)<<4) | (data->year%10));                      /* write year */

    CS_RTC_OFF;
}


__attribute__((mips16)) void RTC_MCP7952x_ReadCalendar(RTC_DATA *data)
{
    CS_RTC_ON;

    SPI1_transfer(RTC_OP_READ);    /* Send write operation */
    SPI1_transfer(RTC_Seconds);     /* Select address */

    data->seconds = SPI1_transfer(0x00);         /* read seconds */
    data->minutes = SPI1_transfer(0x00);         /* read minutes */
    data->hours = SPI1_transfer(0x00);           /* read hours */

    data->day = SPI1_transfer(0x00);             /* read day */
    data->date = SPI1_transfer(0x00);            /* read date */
    data->month = SPI1_transfer(0x00);           /* read month */
    data->year = SPI1_transfer(0x00);            /* read year */

    CS_RTC_OFF;

    /* Formating the data as needed */
    data->seconds = ((data->seconds & 0x70)>>4)*10 + (data->seconds & 0x0F);
    data->minutes = (data->minutes>>4)*10 + (data->minutes & 0x0F);
    data->hours = ((data->hours & 0x30)>>4)*10 + (data->hours & 0x0F);
    data->day = (data->day & 0x07);
    data->date = (data->date>>4)*10 + (data->date & 0x0F);
    data->month = ((data->month & 0x10)>>4)*10 + (data->month & 0x0F);
    data->year = (data->year>>4)*10 + (data->year & 0x0F);

}


__attribute__((mips16)) uint8_t RTC_MCP7952x_CheckVBAT(void)
{
    uint8_t vBat;
    
    CS_RTC_ON;
    
    SPI1_transfer(RTC_OP_READ);         /* Send write operation */
    SPI1_transfer(RTC_Day);             /* Select register Day, VBAT is the bit 4 */
    
    vBat = SPI1_transfer(0x00);
    
    CS_RTC_OFF;


    return ((vBat & 0x10) >> RTC_VBAT_POS);
}


__attribute__((mips16)) void RTC_MCP7952x_ClearVBAT(RTC_DATA *rtcData)
{
    CS_RTC_ON;

    SPI1_transfer(RTC_OP_WRITE);        /* Send write operation */
    SPI1_transfer(RTC_Day);             /* Select address */

    SPI1_transfer((rtcData->day & 0x07) | VBATEN);           /* write day + set VBATEN + Clear VBAT */

    CS_RTC_OFF;
}



__attribute__((mips16)) uint8_t RTC_MCP7952x_CheckPwrFail(RTC_DATA *rtcData)
{
    uint8_t pwrFail;

    /* Check if VBAT is set */
    pwrFail = RTC_MCP7952x_CheckVBAT();

    if (pwrFail == 1)
    {
        CS_RTC_ON;
        SPI1_transfer(RTC_OP_READ);                 // Initiate read //
        SPI1_transfer(RTC_PWRDOWN_Minutes);         // Select first address of Power-Dowm time-stamp //
        rtcData->pwrDown_mm = SPI1_transfer(0x00);
        rtcData->pwrDown_hh = SPI1_transfer(0x00);
        rtcData->pwrDown_date = SPI1_transfer(0x00);
        rtcData->pwrDown_month = SPI1_transfer(0x00);
        CS_RTC_OFF;
        
        delayUs(10);

        CS_RTC_ON;
        SPI1_transfer(RTC_OP_READ);                 // Initiate read //
        SPI1_transfer(RTC_PWRUP_Minutes);           // Select first address of Power-Up time-stamp //
        rtcData->pwrUp_mm = SPI1_transfer(0x00);
        rtcData->pwrUp_hh = SPI1_transfer(0x00);
        rtcData->pwrUp_date = SPI1_transfer(0x00);
        rtcData->pwrUp_month = SPI1_transfer(0x00);
        CS_RTC_OFF;


        /* Formating the data as needed */
        rtcData->pwrDown_mm = (rtcData->pwrDown_mm>>4)*10 + (rtcData->pwrDown_mm & 0x0F);
        rtcData->pwrDown_hh = ((rtcData->pwrDown_hh & 0x30)>>4)*10 + (rtcData->pwrDown_hh & 0x0F);
        rtcData->pwrDown_date = (rtcData->pwrDown_date>>4)*10 + (rtcData->pwrDown_date & 0x0F);
        rtcData->pwrDown_month = ((rtcData->pwrDown_month & 0x01)>>4)*10 + (rtcData->pwrDown_month & 0x0F);

        rtcData->pwrUp_mm = (rtcData->pwrUp_mm>>4)*10 + (rtcData->pwrUp_mm & 0x0F);
        rtcData->pwrUp_hh = ((rtcData->pwrUp_hh & 0x30)>>4)*10 + (rtcData->pwrUp_hh & 0x0F);
        rtcData->pwrUp_date = (rtcData->pwrUp_date>>4)*10 + (rtcData->pwrUp_date & 0x0F);
        rtcData->pwrUp_month = ((rtcData->pwrUp_month & 0x01)>>4)*10 + (rtcData->pwrUp_month & 0x0F);

        /* Clear VBAT to clean the power-stamp registers */
        RTC_MCP7952x_ClearVBAT(rtcData);
    }

    return pwrFail;
}


__attribute__((mips16)) void RTC_MCP7952x_SetCalib(uint8_t cal, uint8_t hh, uint8_t sgn)
{
    CS_RTC_ON;
    SPI1_transfer(RTC_OP_WRITE);                            /* Send write operation */
    SPI1_transfer(RTC_Hours);                               /* Set the address to hours register */
    SPI1_transfer((((hh/10)<<4)&0x30) | (hh%10) | sgn);     /* write hours, set 24h mode and SIGN of Calib */
    CS_RTC_OFF;

    CS_RTC_ON;
    SPI1_transfer(RTC_OP_WRITE);    /* Send write operation */
    SPI1_transfer(RTC_CALIB);       /* Set address to calibration register */
    SPI1_transfer(cal);       /* Send Calibration value */
    CS_RTC_OFF;
}


__attribute__((mips16)) uint8_t RTC_MCP7952x_WaitBusy(void)
{
    uint8_t status=0;

    do
    {
        CS_RTC_ON;

        SPI1_transfer(RTC_OP_SRREAD);       /* Read RTC Status register */
        status = SPI1_transfer(0x00);       /* Send dummy byte to receive status register */

        CS_RTC_OFF;
    }
    while (status & 0x01);                   /* Write in Progress when the 1st bit is set */

    return 0;
}


__attribute__((mips16)) void RTC_MCP7952x_WrtEEPROM_Byte(uint8_t addr, uint8_t dataByte)
{
    CS_RTC_ON;
    SPI1_transfer(RTC_OP_EEWREN);      /*send WRITE_ENABLE command*/
    CS_RTC_OFF;

    CS_RTC_ON;

    SPI1_transfer(RTC_OP_EEWRITE);      /*Initiate write*/
    SPI1_transfer(addr);               /*Select address*/

    SPI1_transfer(dataByte);           /*Write data*/

    CS_RTC_OFF;
}


__attribute__((mips16)) void RTC_MCP7952x_WrtEEPROM_Array(uint8_t addr, uint8_t *data, uint8_t arraySize)
{
    uint8_t i;

    /* Wait if EEPROM is busy */
    RTC_MCP7952x_WaitBusy();

    CS_RTC_ON;
    SPI1_transfer(RTC_OP_EEWREN);      /*send WRITE_ENABLE command*/
    CS_RTC_OFF;

    CS_RTC_ON;

    SPI1_transfer(RTC_OP_EEWRITE);      /*Initiate write*/
    SPI1_transfer(addr);                /*Select address*/

    /* Write 1 byte at a time from the array */
    for(i=0; i<arraySize; i++)
    {
        if ( ((addr+i) % 8 == 0) && (i != 0) )      /* New write cycle must be initiated across 8byte pages */
        {
            CS_RTC_OFF;

            RTC_MCP7952x_WaitBusy();

            CS_RTC_ON;
            SPI1_transfer(RTC_OP_EEWREN);      /*send WRITE_ENABLE command*/
            CS_RTC_OFF;

            CS_RTC_ON;
            SPI1_transfer(RTC_OP_EEWRITE);      /*Initiate write*/
            SPI1_transfer(addr+i);                /*Select address*/
        }

        SPI1_transfer(data[i]);
    }

    CS_RTC_OFF;
}


__attribute__((mips16)) uint8_t RTC_MCP7952x_ReadEEPROM_Byte(uint8_t addr)
{
    uint8_t readByte;

    CS_RTC_ON;

    SPI1_transfer(RTC_OP_EEREAD);
    SPI1_transfer(addr);

    readByte = SPI1_transfer(0x00);     /*Send dummy byte to read 1 byte*/

    CS_RTC_OFF;

    return readByte;
}


__attribute__((mips16)) void RTC_MCP7952x_ReadEEPROM_Array(uint8_t addr, uint8_t *data, uint8_t arraySize)
{
    uint8_t i;

    /* Wait if EEPROM is busy */
    RTC_MCP7952x_WaitBusy();

    CS_RTC_ON;

    SPI1_transfer(RTC_OP_EEREAD);       /*Initiate read*/
    SPI1_transfer(addr);                /*Select address*/

    /* Request and store the array for the length  */
    for(i=0; i<arraySize; i++)
    {
        data[i] = SPI1_transfer(0x00);      /*Send dummy byte to read 1 byte*/
    }

    CS_RTC_OFF;
}


__attribute__((mips16)) void RTC_MCP7952X_ClrEEPROM(void)
{
    uint16_t i, addr;

    /* The address is the 1st position of EEPROM */
    addr = EEPROM_INIT_ADD;

    /* Wait if EEPROM is busy */
    RTC_MCP7952x_WaitBusy();

    CS_RTC_ON;
    SPI1_transfer(RTC_OP_EEWREN);      /*send WRITE_ENABLE command*/
    CS_RTC_OFF;

    CS_RTC_ON;

    SPI1_transfer(RTC_OP_EEWRITE);                  /*Initiate write*/
    SPI1_transfer(addr);                            /*Select address*/

    /* Write 1 byte at a time from the array */
    for(i=0; i<EEPROM_SIZE; i++)
    {
        if ( ((addr+i) % 8 == 0) && (i != 0) )      /* New write cycle must be initiated across 8byte pages */
        {
            CS_RTC_OFF;

            RTC_MCP7952x_WaitBusy();

            CS_RTC_ON;
            SPI1_transfer(RTC_OP_EEWREN);      /*send WRITE_ENABLE command*/
            CS_RTC_OFF;

            CS_RTC_ON;
            SPI1_transfer(RTC_OP_EEWRITE);      /*Initiate write*/
            SPI1_transfer(addr+i);                /*Select address*/
        }

        SPI1_transfer(0xFF);
    }

    CS_RTC_OFF;
}


__attribute__((mips16)) uint8_t RTC_MCP7952x_ClrRAM(void)
{
    CS_RTC_ON;

    SPI1_transfer(RTC_OP_CLRRAM);       /*send Clear RAM command*/
    SPI1_transfer(0x00);                /*Send dummy byte - it's needed to complete the clear ram cmd*/

    CS_RTC_OFF;

    return 0;
}


