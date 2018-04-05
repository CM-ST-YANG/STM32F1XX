
#ifndef __CALLBACK_H__
#define __CALLBACK_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f1xx_hal.h"
#include "RC.h"
#include "PWM.h"
//#include "ultrasound.h"
#include "UART1.h"
#include "UART2.h"
#include "I2C.h"
#include "SPI.h"
#include "KEY.h"

	void SysTick_Handler(void);
	void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
	void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);


#ifdef __cplusplus
}
#endif

#endif
