
#pragma once
#ifndef _KEY_H
#define _KEY_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stm32f1xx_hal.h>  //Òý½Å¶¨Òå
	typedef enum
	{
		KEY_UP = 0,
		KEY_DOWN = 1,
	}KEYState_TypeDef;

#define KEY1_RCC_CLK_ENABLE           __HAL_RCC_GPIOA_CLK_ENABLE
#define KEY1_GPIO_PIN                 GPIO_PIN_0
#define KEY1_GPIO                     GPIOA
#define KEY1_DOWN_LEVEL               1  
#define KEY1_EXTI_IRQn                EXTI0_IRQn
#define KEY1_EXTI_IRQHandler          EXTI0_IRQHandler

#define KEY2_RCC_CLK_ENABLE           __HAL_RCC_GPIOC_CLK_ENABLE
#define KEY2_GPIO_PIN                 GPIO_PIN_13
#define KEY2_GPIO                     GPIOC
#define KEY2_DOWN_LEVEL               0  
#define KEY2_EXTI_IRQHandler          EXTI15_10_IRQHandler
#define KEY2_EXTI_IRQn                EXTI15_10_IRQn

	
	void KEY_GPIO_Init(void);
	KEYState_TypeDef KEY1_StateRead(void);
	KEYState_TypeDef KEY2_StateRead(void);

#define KEY GPIO_PIN_All	
#define KEY1 GPIO_PIN_0
#define KEY2 GPIO_PIN_1
#define KEY3 GPIO_PIN_2
#define KEY4 GPIO_PIN_3
#define KEY5 GPIO_PIN_4
#define KEY6 GPIO_PIN_5
#define KEY7 GPIO_PIN_6
#define KEY8 GPIO_PIN_7
	
	void key_init(void);
	//void led_display(void);
#ifdef __cplusplus
}
#endif


#endif 
