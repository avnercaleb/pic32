/*
 * File:   delay.c
 * Author: André Gomes
 *
 * Compiler:
 * XC32 v1.20
 */

#include "delay.h"


void delayUs(uint16_t us)
{
    uint16_t cnt;

    for(cnt=0; cnt<us; cnt++)
    {
        _nop();_nop();_nop();_nop();
        _nop();_nop();_nop();_nop();
        _nop();_nop();_nop();_nop();
        _nop();_nop();_nop();_nop();
        _nop();_nop();_nop();_nop();
        _nop();_nop();_nop();_nop();
        _nop();_nop();_nop();_nop();
        _nop();_nop();_nop();_nop();
        _nop();_nop();_nop();_nop();
    }
}


__attribute__((mips16)) void delayMs(uint16_t ms)
{
    uint16_t cnt;

    for(cnt=0; cnt<ms; cnt++)
    {
        delayUs(1000);
    }
}



__attribute__((mips16)) void delayS(uint16_t s)
{
    uint16_t cnt;

    for(cnt=0; cnt<s; cnt++)
    {
        delayMs(1000);
    }
}
