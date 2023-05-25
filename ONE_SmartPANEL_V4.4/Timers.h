/* 
 * File:   Timers.h
 * Author: André Gomes
 *
 * Created on 23 de Janeiro de 2013, 16:32
 */

#ifndef TIMERS_H
#define	TIMERS_H

#include <plib.h>
#include <stdint.h>

#include "system.h"



#define TOGGLES_PER_SEC         10
#define CORE_TICK_RATE          (SYS_FREQ/2/TOGGLES_PER_SEC)


__attribute__((mips16)) void CoreTimer_Init(uint32_t period);



#endif	/* TIMERS_H */

