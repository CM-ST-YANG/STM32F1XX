#pragma once
#ifndef __SPI_H__
#define __SPI_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f1xx_hal.h"
#define READWRITE_CMD                     ((uint8_t)0x80) 
#define MULTIPLEBYTE_CMD                  ((uint8_t)0x40)
#define DUMMY_BYTE						  ((uint8_t)0x00)

	void spi1_init(void);
	uint8_t SPI1_WriteRead(uint8_t Byte);
	void ACCELERO_IO_Read(uint8_t *pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead);
	void SPI1_SetSpeed(uint8_t speed);
#ifdef __cplusplus
}
#endif

#endif