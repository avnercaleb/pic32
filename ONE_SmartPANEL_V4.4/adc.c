/*
 * File:   adc.c
 * Author: André Gomes
 *
 * Created on 22 de Fevereiro de 2013, 16:38
 */

#include "adc.h"


volatile ADC_STRUCT adc;
ADC_STRUCT *adcPt;


__attribute__((mips16)) void ADC_ConfigAutoScan(uint8_t nCh, uint16_t analogIns)
{
    AD1CON1 = 0x0000;       // disable ADC

    // AD1CON1<2>, ASAM    : Sampling begins immediately after last conversion completes
    // AD1CON1<7:5>, SSRC  : Internal counter ends sampling and starts conversion (auto convert)
    AD1CON1SET = 0x00E4;

    // AD1CON2<1>, BUFM    : Buffer configured as two 8-word buffers, ADC1BUF7-ADC1BUF0, ADC1BUFF-ADCBUF8
    // AD1CON2<10>, CSCNA  : Scan inputs
    AD1CON2 = 0x0402;

    // AD2CON2<5:2>, SMPI  : Interrupt flag set at after nCh completed conversions
    AD1CON2bits.SMPI = nCh-1;

    // AD1CON3<7:0>, ADCS  : TAD = TPB * 2 * (ADCS<7:0> + 1) = 512 * TPB in this example
    // AD1CON3<12:8>, SAMC : Acquisition time = AD1CON3<12:8> TAD = 16 TAD in this example
    AD1CON3 = 0x10FF;

    // AD1CHS is ignored in scan mode
    AD1CHS = 0;

    /* Config ADC interrupt */
    ConfigIntADC10(ADC_INT_PRI_4 | ADC_INT_SUB_PRI_0 | ADC_INT_ON);

    // select which pins to use for scan mode
    AD1CSSL = analogIns;

    /* Initialization of ADC struct */
    adcPt = &adc;
    memset(adcPt, 0x00, sizeof(ADC_STRUCT));

    /* start ADC */
    EnableADC10();
    
}



__attribute__((mips16)) void ADC_ConfigManual(void)
{
    AD1CON1 = 0x0000;       // disable ADC before configuration

    AD1CON1 = 0x00E0;       // internal counter ends sampling and starts conversion (auto-convert), manual sample
    AD1CON2 = 0;            // AD1CON2<15:13> set voltage reference to pins AVSS/AVDD

    // AD1CON3<7:0>, ADCS  : TAD = TPB * 2 * (ADCS<7:0> + 1) = 512 * TPB in this example
    // AD1CON3<12:8>, SAMC : Acquisition time = AD1CON3<12:8> TAD = 16 TAD in this example
    AD1CON3 = 0x10FF;

    /* Initialization of ADC struct */
    adcPt = &adc;
    memset(adcPt, 0x00, sizeof(ADC_STRUCT));

    /* start ADC */
    EnableADC10();
}




__attribute__((mips16)) uint16_t ADC_Read(uint8_t ch)
{
    AD1CHS = ch << 16;       // AD1CHS<16:19> controls which analog pin goes to the ADC

    AD1CON1bits.SAMP = 1;           // Begin sampling

    while( AD1CON1bits.SAMP );      // wait until acquisition is done
    while( ! AD1CON1bits.DONE );    // wait until conversion done

    return ADC1BUF0;                // result stored in ADC1BUF0
}


