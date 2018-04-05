#include "KEY.h"
void key_init()
{

	GPIO_InitTypeDef GPIO_InitStructure;
	__GPIOA_CLK_ENABLE();


	//	SystemInit();

	GPIO_InitStructure.Pin = KEY1 | KEY2;      //引脚配置

	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
	//GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
	//HAL_GPIO_DeInit(GPIOA, KEY1);
}
	void KEY_GPIO_Init(void)
	{
		/*定义IO口初始化结构体变量 */
		GPIO_InitTypeDef GPIO_InitStruct;

		/* 按键时钟使能 */
		KEY1_RCC_CLK_ENABLE();
		KEY2_RCC_CLK_ENABLE();

		/* 按键1初始化 */
		GPIO_InitStruct.Pin = KEY1_GPIO_PIN;
		GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
		GPIO_InitStruct.Pull = GPIO_PULLDOWN;
		HAL_GPIO_Init(KEY1_GPIO, &GPIO_InitStruct);

		/* 按键2初始化*/
		GPIO_InitStruct.Pin = KEY2_GPIO_PIN;
		GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		HAL_GPIO_Init(KEY2_GPIO, &GPIO_InitStruct);

		/* 中断初始化*/
		HAL_NVIC_SetPriority(KEY1_EXTI_IRQn, 1, 0);
		HAL_NVIC_EnableIRQ(KEY1_EXTI_IRQn);

		HAL_NVIC_SetPriority(KEY2_EXTI_IRQn, 1, 1);
		HAL_NVIC_EnableIRQ(KEY2_EXTI_IRQn);

	}

	KEYState_TypeDef KEY1_StateRead(void)
	{

		if (HAL_GPIO_ReadPin(KEY1_GPIO, KEY1_GPIO_PIN) == KEY1_DOWN_LEVEL)
		{
		
			HAL_Delay(10);
			
			if (HAL_GPIO_ReadPin(KEY1_GPIO, KEY1_GPIO_PIN) == KEY1_DOWN_LEVEL)
			{
			
				while (HAL_GPIO_ReadPin(KEY1_GPIO, KEY1_GPIO_PIN) == KEY1_DOWN_LEVEL);
			
				return KEY_DOWN;
			}
		}

		return KEY_UP;
	}

	KEYState_TypeDef KEY2_StateRead(void)
	{
	
		if (HAL_GPIO_ReadPin(KEY2_GPIO, KEY2_GPIO_PIN) == KEY2_DOWN_LEVEL)
		{
			
			HAL_Delay(10);
			
			if (HAL_GPIO_ReadPin(KEY2_GPIO, KEY2_GPIO_PIN) == KEY2_DOWN_LEVEL)
			{
		
				while (HAL_GPIO_ReadPin(KEY2_GPIO, KEY2_GPIO_PIN) == KEY2_DOWN_LEVEL);
		
				return KEY_DOWN;
			}
		}
		
		return KEY_UP;
	}
