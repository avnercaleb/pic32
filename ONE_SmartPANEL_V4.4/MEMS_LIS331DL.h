/* 
 * File:   MEMS_LIS331DL.h
 * Author: André Gomes
 *
 * Created on 29 de Maio de 2013, 15:22
 */

#ifndef MEMS_LIS331DL_H
#define	MEMS_LIS331DL_H

#include <plib.h>
#include <stdint.h>

#include "SPI.h"


#define CS_MEMS_ON      LATAbits.LATA3=0 /*mPORTASetBits(BIT_3)*/
#define CS_MEMS_OFF     LATAbits.LATA3=1 /*mPORTAClearBits(BIT_3)*/


/******************************************************************************/
/* Operations                                                               */
/******************************************************************************/
#define MEMS_READ           0x80
#define MEMS_WRITE          0x00
#define MEMS_MULTIPLE_ADD   0x40
#define MEMS_SINGLE_ADD     0x00

/******************************************************************************/
/* Register Map                                                               */
/******************************************************************************/
#define MEMS_WHO_AM_I       0x0F
#define MEMS_CTRL_REG1      0x20
#define MEMS_CTRL_REG2      0x21
#define MEMS_CTRL_REG3      0x22
#define MEMS_HP_FILT_RST    0x23
#define MEMS_STATUS_REG     0x27
#define MEMS_OUT_X          0x29
#define MEMS_OUT_Y          0x2B
#define MEMS_OUT_Z          0x2D
#define MEMS_FF_WU_CFG_1    0x30
#define MEMS_FF_WU_SRC_1    0x31
#define MEMS_FF_WU_THS_1    0x32
#define MEMS_FF_WU_DUR_1    0x33
#define MEMS_FF_WU_CFG_2    0x34
#define MEMS_FF_WU_SRC_2    0x35
#define MEMS_FF_WU_THS_2    0x36
#define MEMS_FF_WU_DUR_2    0x37
#define MEMS_CLICK_CFG      0x38
#define MEMS_CLICK_SRC      0x39
#define MEMS_CLICK_THSYX    0x3B
#define MEMS_CLICK_THSZ     0x3C
#define MEMS_CLICK_TL       0x3D
#define MEMS_CLICK_Lat      0x3E
#define MEMS_CLICK_Win      0x3F


/******************************************************************************/
/* Config Map                                                                 */
/******************************************************************************/
#define MEMS_CTRL_REG1_Opt      0x47        /* Active Mode | Z, X, Y axis Enable */
#define MEMS_Default_Opt        0x00        /* Default options for most of the registers */


/* Auxiliary defines for the stability control */
#define MEMS_NOT_SET            -1


typedef struct
{
    int8_t         xxInit;
    int8_t         yyInit;
    int8_t         zzInit;
    int8_t         xx;
    int8_t         yy;
    int8_t         zz;

}MEMS_STRUCT;





uint8_t MEMS_LIS331DL_Test(void);


void MEMS_LIS331DL_Init(void);


void MEMS_LIS331DL_InitReadOutXYZ(MEMS_STRUCT *memsData);


void MEMS_LIS331DL_ReadOutXYZ(MEMS_STRUCT *memsData);


#endif	/* MEMS_LIS331DL_H */

