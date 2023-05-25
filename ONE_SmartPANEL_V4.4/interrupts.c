/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <sys/attribs.h>     /* For __ISR definition                          */

#include "interrupts.h"
#include "user.h"


/******************************************************************************/
/* Interrupt Vector Options                                                   */
/******************************************************************************/
/*                                                                            */
/* VECTOR NAMES:                                                              */
/*                                                                            */
/* _CORE_TIMER_VECTOR          _COMPARATOR_2_VECTOR                           */
/* _CORE_SOFTWARE_0_VECTOR     _UART_2A_VECTOR                                */
/* _CORE_SOFTWARE_1_VECTOR     _I2C_2A_VECTOR                                 */
/* _EXTERNAL_0_VECTOR          _SPI_2_VECTOR                                  */
/* _TIMER_1_VECTOR             _SPI_2A_VECTOR                                 */
/* _INPUT_CAPTURE_1_VECTOR     _I2C_4_VECTOR                                  */
/* _OUTPUT_COMPARE_1_VECTOR    _UART_3_VECTOR                                 */
/* _EXTERNAL_1_VECTOR          _UART_2_VECTOR                                 */
/* _TIMER_2_VECTOR             _SPI_3A_VECTOR                                 */
/* _INPUT_CAPTURE_2_VECTOR     _I2C_3A_VECTOR                                 */
/* _OUTPUT_COMPARE_2_VECTOR    _UART_3A_VECTOR                                */
/* _EXTERNAL_2_VECTOR          _SPI_4_VECTOR                                  */
/* _TIMER_3_VECTOR             _I2C_5_VECTOR                                  */
/* _INPUT_CAPTURE_3_VECTOR     _I2C_2_VECTOR                                  */
/* _OUTPUT_COMPARE_3_VECTOR    _FAIL_SAFE_MONITOR_VECTOR                      */
/* _EXTERNAL_3_VECTOR          _RTCC_VECTOR                                   */
/* _TIMER_4_VECTOR             _DMA_0_VECTOR                                  */
/* _INPUT_CAPTURE_4_VECTOR     _DMA_1_VECTOR                                  */
/* _OUTPUT_COMPARE_4_VECTOR    _DMA_2_VECTOR                                  */
/* _EXTERNAL_4_VECTOR          _DMA_3_VECTOR                                  */
/* _TIMER_5_VECTOR             _DMA_4_VECTOR                                  */
/* _INPUT_CAPTURE_5_VECTOR     _DMA_5_VECTOR                                  */
/* _OUTPUT_COMPARE_5_VECTOR    _DMA_6_VECTOR                                  */
/* _SPI_1_VECTOR               _DMA_7_VECTOR                                  */
/* _I2C_3_VECTOR               _FCE_VECTOR                                    */
/* _UART_1A_VECTOR             _USB_1_VECTOR                                  */
/* _UART_1_VECTOR              _CAN_1_VECTOR                                  */
/* _SPI_1A_VECTOR              _CAN_2_VECTOR                                  */
/* _I2C_1A_VECTOR              _ETH_VECTOR                                    */
/* _SPI_3_VECTOR               _UART_4_VECTOR                                 */
/* _I2C_1_VECTOR               _UART_1B_VECTOR                                */
/* _CHANGE_NOTICE_VECTOR       _UART_6_VECTOR                                 */
/* _ADC_VECTOR                 _UART_2B_VECTOR                                */
/* _PMP_VECTOR                 _UART_5_VECTOR                                 */
/* _COMPARATOR_1_VECTOR        _UART_3B_VECTOR                                */
/*                                                                            */
/* Refer to the device specific .h file in the C32 Compiler                   */
/* pic32mx\include\proc directory for a complete Vector and IRQ mnemonic      */
/* listings for the PIC32 device.                                             */
/*                                                                            */
/* PRIORITY OPTIONS:                                                          */
/*                                                                            */
/* (default) IPL0AUTO, IPL1, IPL2, ... IPL7 (highest)                         */
/*                                                                            */
/* Example Shorthand Syntax                                                   */
/*                                                                            */
/* void __ISR(<Vector Name>,<PRIORITY>) user_interrupt_routine_name(void)     */
/* {                                                                          */
/*     <Clear Interrupt Flag>                                                 */
/* }                                                                          */
/*                                                                            */
/* For more interrupt macro examples refer to the C compiler User Guide in    */
/* the C compiler /doc directory.                                             */
/*                                                                            */
/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/


volatile uint8_t cnt100ms=0, cnt200ms=0, cnt60s=0;
volatile uint16_t cnt3600s=0;
volatile uint16_t cntTempComp=0;
volatile uint16_t cntPwr=0;

volatile uint8_t cntDim=0;

/* Variable to detect zero-cross signal or PIR detenction */
volatile uint8_t cnt0X=0; 

extern volatile UART_STRUCT uart;
extern volatile SYS_STRUCT sys;
extern volatile RF_STRUCT rf;

extern volatile MSGBUFF_STRUCT msgBuff;     /* Struct to create a buffer of the last 3 msgs received */
extern MSGBUFF_STRUCT *msgBuffPt;

extern volatile PWR_CONSUME_STRUCT pwr;

extern volatile ADC_STRUCT adc;

extern volatile DALI_STRUCT dali;          /* Struct for DALI handling */
extern DALI_STRUCT *daliPt;       /* Pointer for the handling of the struct */

uint16_t *daliCmdPt;

uint8_t b, k, n;   /* Auxiliary variable to get the bits for DALI comunication */


/* Auxiliary variable */
//uint8_t i;


/* Core timer interrupt - used for 1 second flag */
void __ISR(_CORE_TIMER_VECTOR, IPL2SOFT) CoreTimerHandler(void)
{
    // clear the interrupt flag
    mCTClearIntFlag();

    cnt100ms++;
       
    /* Reset control flag for zero-cross/PIR detection */
    cnt0X = 0;
    
    /* Counter for 1s flag */
    if (cnt100ms > ONE_SECOND_INT)
    {
        cnt100ms = 0;
        sys.flag1s = 1;
        
        cnt60s++;
        cnt3600s++;
        cntTempComp++;
        cntPwr++;

        if (cnt60s > ONE_MINUTE_INT)
        {
            sys.flag1min = 1;
            cnt60s = 0;
        }

        if (cnt3600s > ONE_HOUR_INT)
        {
            sys.flag1h = 1;
            cnt3600s = 0;
        }

        /* Flag to control the interval of the temperature compensation for the RTC */
        if (cntTempComp > FIVE_MINUTES_INT)
        {
            sys.flagTempComp = 1;
            cntTempComp = 0;
        }

        /* Flag to control the power consumption interval */
        if (cntPwr > pwr.intrF)
        {
            pwr.flag = 1;
            cntPwr = 0;
        }
    
    } // END if (cnt100ms > ONE_SECOND_INT)
    
    // update the period
    UpdateCoreTimer(CORE_TICK_RATE);
}


/* Timer 5 interrupt handler - Dimming control */
void __ISR(_TIMER_5_VECTOR, IPL3SOFT) Timer5Handler(void)
{
    /* The dimming time interval depends on the duty value - 50*duty + 25*/

    /* Increment the duty value */
    if (sys.duty > sys.dutyTmp)
    {
        sys.duty -= sys.dimInt;
    }
    else if (sys.duty < sys.dutyTmp)
    {
        sys.duty += sys.dimInt;
    }

    if (sys.duty == sys.dutyTmp)
    {
        T5CONCLR = 0x8000;      /* Disable Timer 5 */
    }
    else
    {
        /* Update the period of the timer */
        OpenTimer5(T5_ON |  T5_SOURCE_INT | T5_PS_1_32, PR_TIMER_DIM(sys.duty));
    }

    /* Set the duty cycle to the PWM channels */
    PWM_SetDuty(sys.duty);
    
    // In the ONE_MOC Project
    if ( ((sys.duty == PWM_MIN) && (mPORTAReadLatchBits(BIT_2) == 4)) || \
         ((sys.duty > PWM_MIN) && (mPORTAReadLatchBits(BIT_2) == 0)) )
    {
        // Set order to swith the relay */
        sys.switchRelay = SWITCH_RELAY_WAIT;
    }    

    mT5ClearIntFlag();
}


// UART 1 interrupt handler
// it is set at priority level 6 with software context saving
void __ISR(_UART1_VECTOR, IPL6SOFT) IntUart1Handler(void)
{
    // Is this an RX interrupt?
    if (INTGetFlag(INT_SOURCE_UART_RX(UART1)))
    {
        // Get the byte received.
        uart.rxBuff[uart.indRx] = UARTGetDataByte(UART1);

        uart.indRx++;

        if (uart.indRx > UART_BUFF_LEN-1)
        {
            uart.msgReady = 1;
            uart.rxBuff[uart.indRx] = '\0';
        }
        else
        {
            /* Enable Timer 4 */
            OpenTimer4(T4_ON | T4_SOURCE_INT | T4_PS_1_64, PR_TIMER_EOM);
        }

        // Clear the RX interrupt Flag
        INTClearFlag(INT_SOURCE_UART_RX(UART1));
    }
}


/* Timer 4 interrupt handler - Uart1 msg received */
void __ISR(_TIMER_4_VECTOR, IPL2SOFT) Timer4Handler(void)
{
    /* Time-out - All bytes have been received */

    /* Set the last byte to '\0' to enable the handling as a string */
    uart.msgReady = 1;
    uart.rxBuff[uart.indRx] = '\0';

    T4CONCLR = 0x8000;      /* Disable Timer 5 */

    mT4ClearIntFlag();
}


/* RF Interruption */
void __ISR(_EXTERNAL_0_VECTOR, IPL7SOFT)  INT0Interrupt(void)
{
    rf.int_RF = 1;

    mINT0ClearIntFlag();
}



void __ISR(_ADC_VECTOR, IPL5SOFT)  ADCInterrupt(void)
{
    AD1CON1bits.ASAM = 0;           // stop automatic sampling (essentially shut down ADC in this mode)
    DIGOUT_1_ON; 
    // Check which buffers is being written and read the other set
    if (ReadActiveBufferADC10() == 1)
    {
    #if ADC_N_CH == 4
        adc.samples[0][adc.ind] = ADC1BUF0;
        adc.samples[1][adc.ind] = ADC1BUF1;
        adc.samples[2][adc.ind] = ADC1BUF2;
        adc.samples[3][adc.ind] = ADC1BUF3;
    #elif ADC_N_CH == 5
        adc.samples[0][adc.ind] = ADC1BUF0;
        adc.samples[1][adc.ind] = ADC1BUF1;
        adc.samples[2][adc.ind] = ADC1BUF2;
        adc.samples[3][adc.ind] = ADC1BUF3;
        adc.samples[4][adc.ind] = ADC1BUF4;
    #endif
    }
    else
    {
     #if ADC_N_CH == 4
        adc.samples[0][adc.ind] = ADC1BUF8;
        adc.samples[1][adc.ind] = ADC1BUF9;
        adc.samples[2][adc.ind] = ADC1BUFA;
        adc.samples[3][adc.ind] = ADC1BUFB;
    #elif ADC_N_CH == 5
        adc.samples[0][adc.ind] = ADC1BUF8;
        adc.samples[1][adc.ind] = ADC1BUF9;
        adc.samples[2][adc.ind] = ADC1BUFA;
        adc.samples[3][adc.ind] = ADC1BUFB;
        adc.samples[4][adc.ind] = ADC1BUFC;
    #endif
    }

    adc.ind++;

    if (adc.ind > ADC_N_SAMPLES-1)
    {
        // Reset index and set flag to mean calculations
        adc.ind = 0;
        adc.ready = 1;
    }

    AD1CON1bits.ASAM = 1;           // restart automatic sampling
    DIGOUT_1_OFF; 
    mAD1ClearIntFlag();
}





