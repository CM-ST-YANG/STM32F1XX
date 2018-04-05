

#pragma once
#ifndef _DAC_H
#define _DAC_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stm32f1xx_hal.h>  
#define DACx                            DAC
#define DACx_CHANNEL_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()

#define DACx_CLK_ENABLE()               __HAL_RCC_DAC_CLK_ENABLE()
#define DACx_FORCE_RESET()              __HAL_RCC_DAC_FORCE_RESET()
#define DACx_RELEASE_RESET()            __HAL_RCC_DAC_RELEASE_RESET()


#define DACx_CHANNEL_PIN                GPIO_PIN_5
#define DACx_CHANNEL_GPIO_PORT          GPIOA


#define DACx_CHANNEL                    DAC_CHANNEL_2


	extern DAC_HandleTypeDef hdac;
	void HAL_DAC_MspDeInit(DAC_HandleTypeDef* hdac);
	void HAL_DAC_MspInit(DAC_HandleTypeDef* hdac);
	void DAC_init(void);
#ifdef __cplusplus
}
#endif


#endif 

