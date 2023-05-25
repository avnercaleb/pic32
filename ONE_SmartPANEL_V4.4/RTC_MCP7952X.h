/* 
 * File:   RTC_MCP7952X.h
 * Author: André Gomes
 *
 * Created on 28 de Janeiro de 2013, 17:19
 */

#ifndef RTC_MCP7952X_H
#define	RTC_MCP7952X_H

#include <plib.h>
#include <stdint.h>

#include "SPI.h"
#include "delay.h"


#define CS_RTC_ON        LATBbits.LATB9=0   /*mPORTBSetBits(BIT_9)*/
#define CS_RTC_OFF       LATBbits.LATB9=1   /*mPORTBClearBits(BIT_9)*/


/* RTCC Instructions Bytes */
#define RTC_OP_EEREAD       0x03
#define RTC_OP_EEWRITE      0x02
#define RTC_OP_EEWRDI       0x04
#define RTC_OP_EEWREN       0x06
#define RTC_OP_SRREAD       0x05
#define RTC_OP_SRWRITE      0x01
#define RTC_OP_READ         0x13
#define RTC_OP_WRITE        0x12
#define RTC_OP_UNLOCK       0x14
#define RTC_OP_IDWRITE      0x32
#define RTC_OP_IDREAD       0x33
#define RTC_OP_CLRRAM       0x54

/* RTCC Address Map - Special Registers */
#define RTC_CTRL_REG        0x08
#define RTC_CALIB           0x09

/* RTC Address Map - Calendar*/
#define RTC_Seconds         0x01
#define RTC_Minutes         0x02
#define RTC_Hours           0x03
#define RTC_Day             0x04
#define RTC_Date            0x05
#define RTC_Month           0x06
#define RTC_year            0x07

/* RTC Address Map Power-Down Time-Stamp */
#define RTC_PWRDOWN_Minutes     0x18
#define RTC_PWRDOWN_Hours       0x19
#define RTC_PWRDOWN_Date        0x1A
#define RTC_PWRDOWN_Day_Month   0x1B

/* RTC Address Map Power-Up Time-Stamp */
#define RTC_PWRUP_Minutes       0x1C
#define RTC_PWRUP_Hours         0x1D
#define RTC_PWRUP_Date          0x1E
#define RTC_PWRUP_Day_Month     0x1F


/* RTC Control opcions */
#define START_OSC               0x80
#define VBATEN                  0x08
#define VBAT                    0x00


/* Auxiliary defines */
#define EEPROM_SIZE             256         /* EEPROM have 256 Bytes of free space*/
#define EEPROM_INIT_ADD         0x00        /* Fisrt position of the EEPROM */

#define RTC_DATA_SIZE           7
#define RTC_PWR_STP_SIZE        8

#define RTC_VBAT_POS            4


/* Calibration defines */
#define TEMP0                   25          /* Turnover point <C_deg> */
#define TC                      50          /* TC = [0.030 ...0.050 ] PPM * 1000 thermal coefficient of the crystal
                                             * in the equation: calibration = (TC/1000)*(dT*dT) */
#define SGN_NEGATIVE            0x80        /* Option to set negative calibration */
#define SGN_POSITIVE            0x00        /* Option to set positive calibration */


typedef struct
{
    uint8_t     hours;
    uint8_t     minutes;
    uint8_t     seconds;
    uint8_t     day;
    uint8_t     date;
    uint8_t     month;
    uint8_t     year;
    uint16_t    minAbs;
    uint8_t     minOld;
    uint8_t     pwrDown_mm;
    uint8_t     pwrDown_hh;
    uint8_t     pwrDown_date;
    uint8_t     pwrDown_month;
    uint8_t     pwrUp_mm;
    uint8_t     pwrUp_hh;
    uint8_t     pwrUp_date;
    uint8_t     pwrUp_month;

}RTC_DATA;



void RTC_MCP7952x_Init(void);


__attribute__((mips16)) void RTC_MCP7952x_WrtCalendar(RTC_DATA *data);


__attribute__((mips16)) void RTC_MCP7952x_ReadCalendar(RTC_DATA *data);


__attribute__((mips16)) uint8_t RTC_MCP7952x_CheckVBAT(void);


__attribute__((mips16)) void RTC_MCP7952x_ClearVBAT(RTC_DATA *rtcData);


__attribute__((mips16)) uint8_t RTC_MCP7952x_CheckPwrFail(RTC_DATA *rtcData);


__attribute__((mips16)) void RTC_MCP7952x_SetCalib(uint8_t cal, uint8_t hh, uint8_t sgn);


__attribute__((mips16)) uint8_t RTC_MCP7952x_WaitBusy(void);


__attribute__((mips16)) void RTC_MCP7952x_WrtEEPROM_Byte(uint8_t addr, uint8_t dataByte);


__attribute__((mips16)) void RTC_MCP7952x_WrtEEPROM_Array(uint8_t addr, uint8_t *data, uint8_t arraySize);


__attribute__((mips16)) uint8_t RTC_MCP7952x_ReadEEPROM_Byte(uint8_t addr);


__attribute__((mips16)) void RTC_MCP7952x_ReadEEPROM_Array(uint8_t addr, uint8_t *data, uint8_t arraySize);


__attribute__((mips16)) void RTC_MCP7952X_ClrEEPROM(void);


__attribute__((mips16)) uint8_t RTC_MCP7952x_ClrRAM(void);




#endif	/* RTC_MCP7952X_H */

