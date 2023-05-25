/*
 * File:   PWM.h
 * Author: André Gomes
 *
 * Created on 1 de Fevereiro de 2013, 15:26
 */


#include "PWM.h"


__attribute__((mips16)) void PWM_Init(void)
{
    #ifdef PWM_CH3
        OC3CON = OC_PWM_FAULT_PIN_DISABLE | OC_TIMER2_SRC;      /* Set PWM Mode and timer 2 as source*/
        OC3RS = 0;                                              /* Initialize the register for the duty-cycle*/
    #endif

    #ifdef PWM_CH4
        OC4CON = OC_PWM_FAULT_PIN_DISABLE | OC_TIMER2_SRC;      /* Set PWM Mode and timer 2 as source */
        OC4RS = 0;                                              /* Initialize the register for the duty-cycle*/
    #else
        LATBbits.LATB13=1;
    #endif

    /* Open Timer2 with Period register value */
    OpenTimer2(T2_ON | T2_PS_1_8, PR_TIMER_PWM);

    #ifdef PWM_CH3
        OC3CONSET = OC_ON;      /* Enable PWM CH3 */
    #endif

    #ifdef PWM_CH4
        OC4CONSET = OC_ON;      /* Enable PWM CH4 */
    #endif

}


__attribute__((mips16)) void PWM_Ch_SetDuty(uint8_t ch, uint16_t dtTmp)
{
    uint16_t duty;

    duty = dtTmp*DUTY_CONV_COE;

    switch (ch)
    {
        case 3:
            OC3RS = duty;
            break;

        case 4:
            OC4RS = duty;
            break;

        default:
            break;
    }

}


__attribute__((mips16)) void PWM_SetDuty(uint16_t dtTmp)
{
    uint16_t duty;
    
    duty = dtTmp*DUTY_CONV_COE;

    #ifdef PWM_CH3
        OC3RS = duty;
    #endif

    #ifdef PWM_CH4
        OC4RS = duty;
    #endif

}

