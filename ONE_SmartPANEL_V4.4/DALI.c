/*
 * File:   DALI.c
 * Author: Cláudio Monteiro & André Gomes
 *
 * Created on 23 de Janeiro de 2013, 16:32
 */


#include "DALI.h"


//const uint8_t daliDim[101] =  { 0,86,111,126,137,145,151,157,162,166,\
                                170,174,177,180,182,185,187,190,192,194,\
                                195,196,199,201,202,204,205,207,208,209,\
                                210,211,212,213,214,216,217,218,219,219,\
                                220,221,222,223,224,225,225,226,227,228,\
                                228,229,230,231,231,232,233,233,234,234,\
                                235,236,236,237,237,238,239,239,240,240,\
                                241,241,242,242,243,243,244,244,245,245,\
                                246,246,247,247,248,248,249,249,249,250,\
                                250,251,251,251,252,252,252,253,253,253,254 };

const uint8_t daliDim[101] =  { 0,86,89,92,95,98,101,104,107,110,\
                                113,116,119,122,125,128,131,134,137,140,\
                                143,146,149,152,155,158,161,164,167,170,\
                                172,174,176,178,180,182,184,186,188,190,\
                                192,194,196,198,200,202,204,206,208,210,\
                                211,212,213,214,215,216,217,218,219,220,\
                                221,222,223,224,225,226,227,228,229,230,\
                                231,232,233,234,235,236,237,238,239,240,\
                                241,242,243,244,245,246,247,248,249,250,\
                                251,251,251,252,252,252,253,253,253,253,254 };


volatile DALI_STRUCT dali;          /* Struct for DALI handling */
DALI_STRUCT *daliPt;       /* Pointer for the handling of the struct */



/************************************************************
Function		: 	DALInit

Description        	:	Initialize DALI interface to idle
 
Arguments          	: 	Nothing
 
Returns            	: 	Nothing
*************************************************************/
void DALI_Init(void)
{
    // The logic must be inverted (1 = 0) because HW output
    DALI_OUT_HIGH;

    /* Config timer 5 for the dimming - The dimming funtion will enable the timer */
    OpenTimer1(T1_OFF | T1_SOURCE_INT | T1_PS_1_256, PR_TIMER_DALI);
    ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_1 | T1_INT_SUB_PRIOR_0);

    /* Initiliaze rf structs and pointers*/
    daliPt = &dali;
    memset(daliPt, 0x00, sizeof(DALI_STRUCT));

    dali.indb = BYTE_LEN;
}


/************************************************************
Function		: 	DALI_BROADCAST

Description        	:	Broadcasts DALI commands
 
Arguments          	: 	DALI_STRUCT *daliData, uint8_t data
 
Returns            	: 	Nothing
*************************************************************/
void DALI_Broadcast(DALI_STRUCT *daliData, uint8_t data)
{	
    daliData->frame[1] = DALI_BROADCAST_DIM;
    daliData->frame[0] = data;

    daliData->rq2Send = 1;

    /* Enable Timer 1 */
    T1CONSET = 0x8000;
}


/************************************************************
Function                : 	DALI_BORADCAST_DIM

Description        	:	Broadcasts DALI dim commands
 
Arguments          	: 	DALI_STRUCT *daliData, uint8_t dim
 
Returns            	: 	Nothing
*************************************************************/
void DALI_Broadcast_Dim(DALI_STRUCT *daliData, uint8_t dim)
{
    daliData->frame[1] = DALI_BROADCAST_DIM;
    daliData->frame[0] = dim;                     // OFF = 0; 100% = 254

    daliData->rq2Send = 1;

    /* Enable Timer 1 */
    T1CONSET = 0x8000;
}


/************************************************************
Function		: 	DALI_BORADCAST_OFF

Description        	:	Broadcasts OFF command
 
Arguments          	: 	DALI_STRUCT *daliData
 
Returns            	: 	Nothing
*************************************************************/
void DALI_Broadcast_OFF(DALI_STRUCT *daliData)
{
    daliData->frame[1] = DALI_BROADCAST;
    daliData->frame[0] = 0x00;

    daliData->rq2Send = 1;

    /* Enable Timer 1 */
    T1CONSET = 0x8000;
}	


