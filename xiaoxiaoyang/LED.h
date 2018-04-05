#pragma once
#ifndef _led_H
#define _led_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stm32f1xx_hal.h>  //Òý½Å¶¨Òå
#define LED GPIO_PIN_All	
#define LED1 GPIO_PIN_0
#define LED2 GPIO_PIN_1
#define LED3 GPIO_PIN_2
#define LED4 GPIO_PIN_3
#define LED5 GPIO_PIN_4
#define LED6 GPIO_PIN_5
#define LED7 GPIO_PIN_6
#define LED8 GPIO_PIN_7
	void LED_GDB_INIT(void);
	void led_display(void);
	void MX_GPIO_Init(void);
#ifdef __cplusplus
}
#endif


#endif 
