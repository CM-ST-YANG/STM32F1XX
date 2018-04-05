#pragma once
#ifndef __PWM_OUT_H__
#define __PWM_OUT_H__
#define __PWM_PA6 0
#define __PWM_PA7 1
#define __PWM_PA8 2
#define __PWM_PA9 3
#define __PWM_PA10 4
#define __PWM_PB1 5
#define __PWM_PB2 6

#ifdef __cplusplus
extern "C" {
#endif


#include <stm32f1xx_hal.h>

#define PWM_freq	100							//PWM频率设置
#define PWM_Period	10000						//周期频率设置
#define PWM_CLOCK (PWM_freq*PWM_Period)			//PWM时钟频率计算

	typedef struct
	{
		short CH[8];
	}PWM_TypeDef;

	void PWM_init(void);
	void set_pwm_val(char CH, uint32_t val);
	void all_pwm_set();

#ifdef __cplusplus
}
#endif

#endif