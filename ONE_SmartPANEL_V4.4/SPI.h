/* 
 * File:   SPI.h
 * Author: André Gomes
 *
 * Created on 24 de Janeiro de 2013, 12:43
 */

#ifndef SPI_H
#define	SPI_H


#include <plib.h>
#include <stdint.h>

#include "system.h"


#define SPI_BAUDRATE        1000000UL



__attribute__((mips16)) void SPI_Init(SpiChannel chnn, uint32_t spiBaudrate);


/* SPI1_transfer() - write to and read from SPI1 buffer */
__attribute__((mips16)) uint8_t SPI1_transfer( uint8_t dataByte);



#endif	/* SPI_H */

