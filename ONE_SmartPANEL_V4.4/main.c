/******************************************************************************/
/*  Files to Include                                                          */
/******************************************************************************/

#include "user.h"


/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

extern volatile SYS_STRUCT sys;
extern SYS_STRUCT *sysPt;

extern ALARM_STRUCT alr;
extern ALARM_STRUCT *alrPt;

extern PWR_LF_CAL_STRUCT pwrLFcal;
extern PWR_LF_CAL_STRUCT *pwrLFcalPt;

extern volatile PWR_CONSUME_STRUCT pwr;
extern PWR_CONSUME_STRUCT *pwrPt;

extern volatile ADC_STRUCT adc;
extern ADC_STRUCT *adcPt;

extern volatile UART_STRUCT uart;
extern UART_STRUCT *uartPt;

extern RTC_DATA rtc;
extern RTC_DATA *rtcPt;

extern volatile RF_STRUCT rf;
extern RF_STRUCT *rfPt;

extern volatile MSGBUFF_STRUCT msgBuff;     /* Struct to create a buffer of the last 3 msgs received */
extern MSGBUFF_STRUCT *msgBuffPt;

extern volatile MEMS_STRUCT mems;
extern MEMS_STRUCT *memsPt;

extern PROF_STRUCT prof;                /* Profiles struct */
extern PROF_STRUCT *profPt;

extern ASTRO_STRUCT astro;
extern ASTRO_STRUCT *astroPt;           /* Astronomical Clock struct */

extern volatile DALI_STRUCT dali;       /* Struct for DALI handling */
extern DALI_STRUCT *daliPt;             /* Pointer for the handling of the struct */
extern const uint8_t daliDim[100];

extern PM_STRUCT pm;
extern PM_STRUCT *pmPt;

extern float i1;
extern float flowSum;
extern float flowAvg;
extern float flowAct;
extern unsigned int avgCnt;

extern const uint8_t modbusQuery[8];

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int32_t main(void)
{
    uint8_t pwrFlag;
    
    uint16_t aux;
    
    
    /*This function sets the PB divider, the Flash Wait States, and the DRM
    wait states to the optimum value.  It also enables the cacheability for
    the K0 segment.  It could has side effects of possibly alter the pre-fetch
    buffer and cache.  It sets the RAM wait states to 0. */
    SYSTEMConfigPerformance(SYS_FREQ);      
    
    /* Initialise I/O and Peripherals for application */
    Config_IO_Peripherals();
    
    /* Reset Watchdog timer */
    WDTCONSET = 0x01;

    /*Configure Multivector Interrupt Mode.  Using Single Vector Mode
    is expensive from a timing perspective, so most applications
    should probably not use a Single Vector Mode*/
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);

    // Enable interrupts
    INTEnableInterrupts();
    
    /* Update calendar info & update absolute minutes */
    RTC_MCP7952x_ReadCalendar(rtcPt);
    rtc.minAbs = rtc.hours*60 + rtc.minutes;
    rtc.minOld = rtc.minutes;

    /* Initialise the Astronomical Clock */
    if ((sys.profileStt == DIM_ASTROCLK_ON) || (sys.profileStt == DIM_PROF_ASTO_ON))
        SYS_AstroClkCheck(astroPt, rtcPt);
    else
        astroPt->dimStt = SYS_ON;

    /* Reset Watchdog timer */
    WDTCONSET = 0x01; 

    /* Check for power failure events */
    pwrFlag = RTC_MCP7952x_CheckPwrFail(rtcPt);

#if DEBUG_PWR_FAIL
    if (pwrFlag == 1)
    {
        sprintf(uart.txBuff, "\nPwrDown - %d:%d | %d/%d\nPwrUp - %d:%d | %d/%d\n\n", rtc.pwrDown_hh, rtc.pwrDown_mm, \
                rtc.pwrDown_date, rtc.pwrDown_month, rtc.pwrUp_hh, rtc.pwrUp_mm, rtc.pwrUp_date, rtc.pwrUp_month);
        UART_PrintString(uart.txBuff);
    }
#endif
    
    /* Infinite cycle */
    while(1)
    {
        /* Reset Watchdog timer */
        WDTCONSET = 0x01;
    
        /* Run the state-machine control */
        SYS_SttMachine(sysPt, profPt, astroPt, rtcPt, alrPt, rfPt, pwrLFcalPt, pwrPt, daliPt);

        /* Check if there is any RF interrupt*/
        if (rf.int_RF == 1)
        {
            /* Call RF State Machine to handle with the interrupt */            
            #ifdef RF_RFM22B
                RF_RFM22B_SttMachine(rfPt, msgBuffPt, sysPt, rtcPt, profPt, astroPt, pmPt);
            #endif
            #ifdef RF_RFM69HCW
                RF_RFM69HCW_SttMachine(rfPt, msgBuffPt, sysPt, rtcPt, profPt, astroPt);
            #endif
            #ifdef RF_RFM95W
                RF_RFM95W_SttMachine(rfPt, msgBuffPt, sysPt, rtcPt, profPt, astroPt);
            #endif

            rf.int_RF = 0;
        }


        /* Avoid missed INT0 interrupts */
#ifdef RF_RFM22B
        if ((rf.int_RF == 0) && (mPORTBReadBits(BIT_7) == 0))
#endif
#ifdef RF_RFM69HCW
        if ((rf.int_RF == 0) && (mPORTBReadBits(BIT_7) == 1))
#endif 
#ifdef RF_RFM95W
        if ((rf.int_RF == 0) && (mPORTBReadBits(BIT_7) == 1))
#endif
        {
            rf.int_RF = 1;
            
            #if DEBUG_RF_INT
                UART_PrintString("\n RF Int missed! \n");
            #endif
        }


        /* Check if there is an order to send a message*/
        if (rf.msgIDsend > 0)
        {
            RF_SendMsg(rfPt, msgBuffPt, sysPt, rtcPt, profPt, alrPt, pwrPt, pmPt);
            rf.msgIDsend = 0;
        }
        

        /* Check if there is any data to update */
        if ((sys.updateID > NO_UPDATE) && (rf.int_RF == 0))
        {
            SYS_Update(sysPt, rtcPt, profPt, astroPt, memsPt, alrPt, pwrLFcalPt);
        }


        /* Calculation of the mean values for the ADC channels */
        if (adc.ready == 1)
        {
            SYS_MeanADCcalc(sysPt, adcPt);
            //CalcFlowAvg();
            adc.ready = 0;
        }


        /* Check if there is any msg received*/
        if (uart.msgReady == 1)
        {
           UART_ProcessMsg(uartPt, sysPt, pmPt, pwrPt, rfPt, rtcPt);
           uart.msgReady = 0;
        }


        /* Temperature compensation for the RTC clock */
        if (sys.flagTempComp == 1)
        {
            RTC_MCP7952x_TempComp(sysPt, rtc.hours);
            sys.flagTempComp = 0;

            #if DEBUG_RTC_CALIB
                sprintf(uart.txBuff, "\nSetting RTC Calibration: %d\n\n",sys.calib);
                UART_PrintString(uart.txBuff);
            #endif
        }
        
        if (pwr.flag == 1)
        {
            /* Calculate the power consumption, divide by 4 (represent 1/4 of an hour of consumption */
            //SYS_calcVolume(pwrPt);
            pwr.flag = 0;
        }

        /* Control 1minute tasks, if it is the first 1s enter in the function */
        if ((sys.flag1min == 1) || ((sys.flagInit == 1) && (sys.flag1s == 1)))
        {            
            // This function will now run only at 1min of interval
            if (sys.flag1min == 1)
            {
                UART1_Send_Array(modbusQuery, sizeof(modbusQuery));  // Send Modbus query every 1 sec
            }
            
            SYS_1minCtrl(sysPt, rtcPt, profPt, rfPt, pwrLFcalPt);                             
            sys.flag1min = 0;
        }


        /* Control for 1s tasks */
        if (sys.flag1s == 1)
        {
            SYS_1sUpdate(rfPt, sysPt, rtcPt, profPt, astroPt, pwrLFcalPt, alrPt, pwrPt, pmPt);
            
            sys.flag1s = 0;
                                  
            //rf.msgIDsend = ANS_TELEM_EXT; /* Used for testing TX */  
            
        } // END if (sys.flag1s == 1)

        
        /* Control for 1h tasks */
        if (sys.flag1h == 1)
        {
            SYS_1hUpdate(sysPt, rfPt);
            sys.flag1h = 0;
        }
                
    } // END while(1)

} // END main(void)
