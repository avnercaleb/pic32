/*
 * File:   SPI.c
 * Author: André Gomes
 *
 * Created on 24 de Janeiro de 2013, 12:43
 */


#include "SPI.h"



__attribute__((mips16)) void SPI_Init(SpiChannel chn, uint32_t spiBaudrate)
{
    SpiOpenFlags spiFlags;        // SPI configs
    uint16_t srcClkDiv;

    srcClkDiv = GetPeripheralClock() / spiBaudrate;

    spiFlags = SPI_OPEN_MSTEN | SPI_OPEN_CKE_REV | SPI_OPEN_MODE8;

    SpiChnOpen(chn, spiFlags, srcClkDiv);
}


/* SPI1_transfer() - write to and read from SPI1 buffer */
__attribute__((mips16)) uint8_t SPI1_transfer(uint8_t dataByte)
{
    SPI1BUF = dataByte;                     // write to buffer for TX

    while(!SPI1STATbits.SPIRBF);            // wait transfer complete

    return SPI1BUF;                         // read the received value
}


