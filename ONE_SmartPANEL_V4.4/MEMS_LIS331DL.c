/*
 * File:   MEMS_LIS331DL.h
 * Author: André Gomes
 *
 * Created on 29 de Maio de 2013, 15:22
 */

#include "MEMS_LIS331DL.h"


MEMS_STRUCT mems;
MEMS_STRUCT *memsPt;


uint8_t MEMS_LIS331DL_Test(void)
{
    uint8_t ans;

    CS_MEMS_ON;
    SPI1_transfer(MEMS_WHO_AM_I | MEMS_READ | MEMS_SINGLE_ADD);
    ans = SPI1_transfer(0x00);
    CS_MEMS_OFF;

    return ans;
}


void MEMS_LIS331DL_Init(void)
{
    /* Configuration of the Config Registers */
    CS_MEMS_ON;
    SPI1_transfer(MEMS_CTRL_REG1 | MEMS_WRITE | MEMS_MULTIPLE_ADD);
    SPI1_transfer(MEMS_CTRL_REG1_Opt);      /* Set power mode to active and enable X, Y & Z axis */
    SPI1_transfer(MEMS_Default_Opt);        /* Mantain default settings to other register */
    SPI1_transfer(MEMS_Default_Opt);
    CS_MEMS_OFF;

    //Initialize MEMS struct and pointer
    memsPt = &mems;
    memset(memsPt, 0x00, sizeof(MEMS_STRUCT));
}


void MEMS_LIS331DL_InitReadOutXYZ(MEMS_STRUCT *memsData)
{
    CS_MEMS_ON;
    SPI1_transfer(MEMS_OUT_X | MEMS_READ | MEMS_SINGLE_ADD);
    memsData->xxInit = SPI1_transfer(0x00);
    CS_MEMS_OFF;

    CS_MEMS_ON;
    SPI1_transfer(MEMS_OUT_Y | MEMS_READ | MEMS_SINGLE_ADD);
    memsData->yyInit = SPI1_transfer(0x00);
    CS_MEMS_OFF;

    CS_MEMS_ON;
    SPI1_transfer(MEMS_OUT_Z | MEMS_READ | MEMS_SINGLE_ADD);
    memsData->zzInit = SPI1_transfer(0x00);
    CS_MEMS_OFF;
}


void MEMS_LIS331DL_ReadOutXYZ(MEMS_STRUCT *memsData)
{
    CS_MEMS_ON;
    SPI1_transfer(MEMS_OUT_X | MEMS_READ | MEMS_SINGLE_ADD);
    memsData->xx = SPI1_transfer(0x00);
    CS_MEMS_OFF;

    CS_MEMS_ON;
    SPI1_transfer(MEMS_OUT_Y | MEMS_READ | MEMS_SINGLE_ADD);
    memsData->yy = SPI1_transfer(0x00);
    CS_MEMS_OFF;

    CS_MEMS_ON;
    SPI1_transfer(MEMS_OUT_Z | MEMS_READ | MEMS_SINGLE_ADD);
    memsData->zz = SPI1_transfer(0x00);
    CS_MEMS_OFF;
}

