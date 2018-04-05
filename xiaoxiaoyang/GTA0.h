#pragma once
#ifndef __GTA0_H__
#define __GTA0_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f1xx_hal.h"
	void SPEED_A(int8_t *angle, int8_t *speed1, int8_t *accel1,int8_t *accel2);

#ifdef __cplusplus
}
#endif

#endif