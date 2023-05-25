/* 
 * File:   UART.h
 * Author: André Gomes
 *
 * Created on 18 de Janeiro de 2013, 12:24
 */

#ifndef UART_H
#define	UART_H

#include <plib.h>
#include <stdint.h>

#include "system.h"


//#define UART_BAUDRATE           (4800UL)      //The desired BaudRate
#define UART_BAUDRATE           (9600UL)      //The desired BaudRate
//#define UART_BAUDRATE           (38400UL)      //The desired BaudRate
//#define UART_BAUDRATE           (115200UL)      //The desired BaudRate
//#define UART_BAUDRATE           (19200UL)         //The desired BaudRate

#define UART_BUFF_LEN           (256)


typedef struct
{
    uint8_t     txBuff[UART_BUFF_LEN];
    uint16_t    indTx;
    uint8_t     rxBuff[UART_BUFF_LEN];
    uint16_t    indRx;
    uint8_t     msgReady;

}UART_STRUCT;


/* UART1 */

/* UART 1 Initialization */
__attribute__((mips16)) void UART_Init(UART_MODULE id, uint32_t baudrate);


__attribute__((mips16)) void UART_PrintString(const uint8_t *string);


__attribute__((mips16)) void UART_PutChar(const uint8_t character);


__attribute__((mips16)) void UART1_Send_Array (const uint8_t *array, const uint8_t len);


/* UART2 */
__attribute__((mips16)) void UART2_Send_Array (const uint8_t *array, const uint8_t len);



/* No UART pre-defined */
__attribute__((mips16)) void UART_Send_Array (UART_MODULE id, const uint8_t *array, const uint8_t len);


__attribute__((mips16)) void UART_ClearBuff(uint8_t *buffer, uint16_t *ind);


#endif	/* UART_H */

