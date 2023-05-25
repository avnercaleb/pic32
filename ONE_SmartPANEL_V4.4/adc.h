/* 
 * File:   adc.h
 * Author: André Gomes
 *
 * Created on 22 de Fevereiro de 2013, 16:38
 */

#ifndef ADC_H
#define	ADC_H


#include <plib.h>
#include <stdint.h>


/******************************************************************************/
/* ADC behaviour defines                                                       /
/******************************************************************************/
#define ADC_N_CH            4
#define ADC_N_SAMPLES       16
#define ADC_MAX_VALUE       1024


#define EN_AN0             (1 << _AD1CSSL_CSSL0_POSITION)       /*AN0 enable for Input Scan */
#define EN_AN1             (1 << _AD1CSSL_CSSL1_POSITION)       /*AN1 enable for Input Scan */
#define EN_AN2             (1 << _AD1CSSL_CSSL2_POSITION)       /*AN2 enable for Input Scan */
#define EN_AN3             (1 << _AD1CSSL_CSSL3_POSITION)       /*AN3 enable for Input Scan */
#define EN_AN4             (1 << _AD1CSSL_CSSL4_POSITION)       /*AN4 enable for Input Scan */
#define EN_AN5             (1 << _AD1CSSL_CSSL5_POSITION)       /*AN5 enable for Input Scan */
#define EN_AN6             (1 << _AD1CSSL_CSSL6_POSITION)       /*AN6 enable for Input Scan */
#define EN_AN7             (1 << _AD1CSSL_CSSL7_POSITION)       /*AN7 enable for Input Scan */
#define EN_AN8             (1 << _AD1CSSL_CSSL8_POSITION)       /*AN8 enable for Input Scan */
#define EN_AN9             (1 << _AD1CSSL_CSSL9_POSITION)       /*AN9 enable for Input Scan */
#define EN_AN10            (1 << _AD1CSSL_CSSL10_POSITION)      /*AN10 enable for Input Scan */
#define EN_AN11            (1 << _AD1CSSL_CSSL11_POSITION)      /*AN11 enable for Input Scan */
#define EN_AN12            (1 << _AD1CSSL_CSSL12_POSITION)      /*AN12 enable for Input Scan */
#define EN_AN13            (1 << _AD1CSSL_CSSL13_POSITION)      /*AN13 enable for Input Scan */
#define EN_AN14            (1 << _AD1CSSL_CSSL14_POSITION)      /*AN14 enable for Input Scan */
#define EN_AN15            (1 << _AD1CSSL_CSSL15_POSITION)      /*AN15 enable for Input Scan */
#define EN_ALL             (0xFFFF)                             /*Enable AN0-AN15 for Input Scan */



typedef struct
{
    uint8_t  ind;
    uint8_t  ready;
    uint16_t samples[ADC_N_CH][ADC_N_SAMPLES];

}ADC_STRUCT;



__attribute__((mips16)) void ADC_ConfigAutoScan(uint8_t nCh, uint16_t analogIns);


__attribute__((mips16)) void ADC_ConfigManual(void);


__attribute__((mips16)) uint16_t ADC_Read(uint8_t ch);



#endif	/* ADC_H */

