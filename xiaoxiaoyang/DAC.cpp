#include "DAC.h"
DAC_HandleTypeDef hdac;
void DAC_init()
{
	DAC_ChannelConfTypeDef sConfig;

	//DAC初始化
	hdac.Instance = DACx;
	HAL_DAC_Init(&hdac);
	//输出通道配置
	sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
	sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_DISABLE;
	HAL_DAC_ConfigChannel(&hdac, &sConfig, DACx_CHANNEL);

}

void HAL_DAC_MspInit(DAC_HandleTypeDef* hdac)//hal库内部调用
{
	GPIO_InitTypeDef GPIO_InitStruct;
	if (hdac->Instance == DACx)
	{
		
		DACx_CLK_ENABLE();

		
		DACx_CHANNEL_GPIO_CLK_ENABLE();

		
		GPIO_InitStruct.Pin = DACx_CHANNEL_PIN;
		GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(DACx_CHANNEL_GPIO_PORT, &GPIO_InitStruct);
	}
}

void HAL_DAC_MspDeInit(DAC_HandleTypeDef* hdac)
{

	if (hdac->Instance == DAC)
	{
		
		DACx_FORCE_RESET();
		DACx_RELEASE_RESET();

		
		__HAL_RCC_DAC_CLK_DISABLE();

		
		HAL_GPIO_DeInit(DACx_CHANNEL_GPIO_PORT, DACx_CHANNEL_PIN);
	}
}