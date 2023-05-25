/*
 * File:   DALI.h
 * Author: Cláudio Monteiro & André Gomes
 *
 * Created on 23 de Janeiro de 2013, 16:32
 */

#ifndef DALI_H
#define	DALI_H

#include <plib.h>
#include <stdint.h>

#include "delay.h"
#include "UART.h"


#define DALI_OUT_HIGH       mPORTBClearBits(BIT_11)         /* DALI_OUT is the RB11 pin - The logic is inverted,... */
#define DALI_OUT_LOW        mPORTBSetBits(BIT_11)           /* once the hardware invertes the signal */


#define DALI_IN             mPORTAReadBits(BIT_4)           /* DALI_IN is the RA4 pin */

/* Definitions for the DALI timer */
#define DALI_TIME           0.000416    /* Time for the half bit in seconds - TE */
#define TMR_PRE_DALI        256         /* Pre-scaler timer */
#define PR_TIMER_DALI       65          /* (SYS_FREQ * DIM_TIME) / TMR_PRE_DALI */


#define DALI_ON             254
#define DALI_OFF            0
#define DALI_ON_UP          8
#define DALI_LAMP_FAIL      146
#define DALI_MIN_DIM        222
#define DALI_MAX_DIM        254

#define DELAY_26TE          26      /* 4TE + 22TE - stop sequence + wait time */
#define DALI_CMD_LEN        34      /* There are 2 bits (start) + 16 bits (cmd), but there is the Manchester coding */
#define BYTE_LEN            16U     /* Once there are to stages for each byte the size is the double */

#define DALI_BROADCAST      0xFF
#define DALI_BROADCAST_DIM  0xFE

#define DALI_TIME2SEND      4       /* Interval in seconds to send broadcast dimming messages - Redundance */

#define DUTY_TO_DALIDIM(x)          (uint8_t)((x/10) * 2.54)



typedef struct
{
    uint8_t frame[2];       /* Index 0 -> DATA, Index 1 -> CMD */
    uint8_t indTE;          /* Index of the TE -> Start + the bits already sent */
    uint8_t indb;           /* Index of the bits */
    uint8_t rq2Send;        /* Request to start the DALI trasmission */
    uint8_t delay;          /* Variable to count the 24TE needed to send another forward message */
    uint8_t tm2sndFlag;     /* Flag to indicate the time to send broadcast dimming messages - Redundance */

}DALI_STRUCT;



/************************************************************
Function		: 	DALInit

Description        	:	Initialize DALI interface to idle

Arguments          	: 	Nothing

Returns            	: 	Nothing
*************************************************************/
void DALI_Init(void);


/************************************************************
Function		: 	DALI_BROADCAST

Description        	:	Broadcasts DALI commands

Arguments          	: 	DALI_STRUCT *daliData, uint8_t data

Returns            	: 	Nothing
*************************************************************/
void DALI_Broadcast(DALI_STRUCT *daliData, uint8_t data);


/************************************************************
Function                : 	DALI_BORADCAST_DIM

Description        	:	Broadcasts DALI dim commands

Arguments          	: 	DALI_STRUCT *daliData, uint8_t dim

Returns            	: 	Nothing
*************************************************************/
void DALI_Broadcast_Dim(DALI_STRUCT *daliData, uint8_t dim);


/************************************************************
Function		: 	DALI_BORADCAST_OFF

Description        	:	Broadcasts OFF command

Arguments          	: 	DALI_STRUCT *daliData

Returns            	: 	Nothing
*************************************************************/
void DALI_Broadcast_OFF(DALI_STRUCT *daliData);




#endif
