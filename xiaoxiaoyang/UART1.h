#ifndef __URAT1_H__
#define __URAT1_H__

#ifdef __cplusplus

extern "C" {
#endif


#include "stm32f1xx_hal.h"
#include "string.h"

	void uart1_init(void);
	void uart1_send(const char *b);
	void UART1_Handler(void);
	
#ifdef __cplusplus
}
#endif

#endif#pragma once
