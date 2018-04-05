#ifndef __URAT2_H__
#define __URAT2_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f1xx_hal.h"
#include "string.h"

	void uart2_init(void);
	void uart2_send(const char *b);
	void UART2_Handler(void);


#ifdef __cplusplus
}
#endif

#endif#pragma once
