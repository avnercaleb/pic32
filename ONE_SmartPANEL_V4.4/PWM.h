/* 
 * File:   PWM.h
 * Author: André Gomes
 *
 * Created on 1 de Fevereiro de 2013, 15:26
 */

#ifndef PWM_H
#define	PWM_H


#include <plib.h>
#include <stdint.h>

#include "system.h"
#include "delay.h"


#define  PWM_CH3        /* Define PWM3 Channel */
#define  PWM_CH4        /* Define PWM4 Channel */

#define PWM_MAX         1000        /* The PWM channel is configure to have a resolution of 1000:1 */
#define PWM_10PERCENT   100         /* The PWM value for 10% */
#define PWM_MIN         0

/* PRy configures the PWM frequency, with the following expression
 * PR = [FPB / (PWM Frequency * TMR Prescale Value)] ? 1 */
#define PWM_FREQUENCY       200     /* Value in Hz for the PWM Frequency */
#define TMR_PRE_PWM         8
#define PR_TIMER_PWM        (SYS_FREQ / (PWM_FREQUENCY * TMR_PRE_PWM) - 1)
#define DUTY_CONV_COE       25      /* PR_TIMER_PWM+1/1000 */



__attribute__((mips16)) void PWM_Init(void);


__attribute__((mips16)) void PWM_Ch_SetDuty(uint8_t ch, uint16_t dtTmp);


__attribute__((mips16)) void PWM_SetDuty(uint16_t dtTmp);







#endif	/* PWM_H */

