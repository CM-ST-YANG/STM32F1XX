#include "CALLBACK.h"



void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	/*if (GPIO_Pin == GPIO_PIN_4)
	{
		ultrasound_Callback(GPIO_Pin);
	}

	if (GPIO_Pin > GPIO_PIN_9)
	{
		RC_Callback(GPIO_Pin);
	}*/
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	if (huart->Instance == USART1)
	{
		UART1_Handler();
	}
	else if (huart->Instance == USART2)
	{
		UART2_Handler();
	}

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin,uint8_t state)
{
	if (GPIO_Pin == KEY1_GPIO_PIN)
	{
		HAL_Delay(20);
		if (HAL_GPIO_ReadPin(KEY1_GPIO, KEY1_GPIO_PIN) == KEY1_DOWN_LEVEL)
		{
			state = !state;
		}
		__HAL_GPIO_EXTI_CLEAR_IT(KEY1_GPIO_PIN);
	}
	else if (GPIO_Pin == KEY2_GPIO_PIN)
	{
		HAL_Delay(20);
		if (HAL_GPIO_ReadPin(KEY2_GPIO, KEY2_GPIO_PIN) == KEY2_DOWN_LEVEL)
		{
			
		}
		__HAL_GPIO_EXTI_CLEAR_IT(KEY2_GPIO_PIN);
	}
}