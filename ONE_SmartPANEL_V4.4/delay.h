/* 
 * File:   delay.h
 * Author: André Gomes
 *
 * Created on 18 de Janeiro de 2013, 16:33
 */

#ifndef DELAY_H
#define	DELAY_H


#include <plib.h>
#include <stdint.h>


void delayUs(uint16_t us);


__attribute__((mips16)) void delayMs(uint16_t ms);


__attribute__((mips16)) void delayS(uint16_t s);



#endif	/* DELAY_H */

