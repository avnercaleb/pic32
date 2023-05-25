/*
 * File:   UART.c
 * Author: André Gomes
 *
 * Compiler:
 * XC32 v1.20
 */

#include "UART.h"


volatile UART_STRUCT uart;
UART_STRUCT *uartPt;


/* UART1 */

/* UART 1 Initialization */
__attribute__((mips16)) void UART_Init(UART_MODULE id, uint32_t baudrate)
{

    UARTConfigure(id, UART_ENABLE_PINS_TX_RX_ONLY);
    UARTSetFifoMode(id, UART_INTERRUPT_ON_RX_NOT_EMPTY);
    UARTSetLineControl(id, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
    UARTSetDataRate(id, GetPeripheralClock(), baudrate);
    UARTEnable(id, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

    // Configure UART1 RX Interrupt
    INTEnable(INT_SOURCE_UART_RX(id), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(id), INT_PRIORITY_LEVEL_6);
    INTSetVectorSubPriority(INT_VECTOR_UART(id), INT_SUB_PRIORITY_LEVEL_0);

    /* Initialize UART struct and pointer*/
    uartPt = &uart;
    memset(uartPt, 0x00, sizeof(uart));

}


__attribute__((mips16)) void UART_PrintString(const uint8_t *string)
{
    while (*string != '\0')
    {
        while (!UARTTransmitterIsReady(UART1))
            ;

        UARTSendDataByte(UART1, *string);

        string++;

        while (!UARTTransmissionHasCompleted(UART1))
            ;
    }
}


__attribute__((mips16)) void UART_PutChar(const uint8_t character)
{
    while (!UARTTransmitterIsReady(UART1))
        ;

    UARTSendDataByte(UART1, character);

    while (!UARTTransmissionHasCompleted(UART1))
        ;
}


__attribute__((mips16)) void UART1_Send_Array (const uint8_t *array, const uint8_t len)
{
    uint8_t i;
    
    for (i=0; i<len; i++)
    {
        while (!UARTTransmitterIsReady(UART1))
            ;

        UARTSendDataByte(UART1, *array);

        array++;

        while (!UARTTransmissionHasCompleted(UART1))
            ;
    }
}



/* UART2 */

__attribute__((mips16)) void UART2_Send_Array (const uint8_t *array, const uint8_t len)
{
    uint8_t i;

    for (i=0; i<len; i++)
    {
        while (!UARTTransmitterIsReady(UART2))
            ;

        UARTSendDataByte(UART2, *array);

        array++;

        while (!UARTTransmissionHasCompleted(UART2))
            ;
    }
}



/* No UART pre-defined */

__attribute__((mips16)) void UART_Send_Array (UART_MODULE id, const uint8_t *array, const uint8_t len)
{
    uint8_t i;

    for (i=0; i<len; i++)
    {
        while (!UARTTransmitterIsReady(id))
            ;

        UARTSendDataByte(id, *array);

        array++;

        while (!UARTTransmissionHasCompleted(id))
            ;
    }
}



__attribute__((mips16)) void UART_ClearBuff(uint8_t *buffer, uint16_t *ind)
{
    memset(buffer, 0x00, UART_BUFF_LEN);
    *ind = 0;
}
