#include "SYSTEM.h"
#ifdef USE_UCOSII_OS
#include "os_includes.h"
#endif
int8_t SYSTEM_SetClock(uint8_t freq)
{
	ErrorStatus HSEStartUpStatus;
	uint32_t pllMul;

	/* 选择倍频系数 */
	switch (freq)
	{
	case(32) :
		pllMul = RCC_PLLMul_4;
		break;
	case(40) :
		pllMul = RCC_PLLMul_5;
		break;
	case(48) :
		pllMul = RCC_PLLMul_6;
		break;
	case(56) :
		pllMul = RCC_PLLMul_7;
		break;
	case(64) :
		pllMul = RCC_PLLMul_8;
		break;
	case(72) :
		pllMul = RCC_PLLMul_9;
		break;
	default:
		RCC_DeInit();
		return -1;
	}

	/*复位RCC */
	RCC_DeInit();

	/*使能打开HSE外部高速时钟 */
	RCC_HSEConfig(RCC_HSE_ON);

	/* 等待HSE时钟准备就绪*/
	HSEStartUpStatus = RCC_WaitForHSEStartUp();

	/* 当HSE时钟准备就绪 */
	if (HSEStartUpStatus == SUCCESS)
	{
		/* 使能开启FLASH ,允许程序去操作FLASH上面的数据，要是不设置程序会出错 */
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

		/* FLASH代码两个延时周期 */
		FLASH_SetLatency(FLASH_Latency_2);

		/* 设置AHB总线的时钟分频 */
		RCC_HCLKConfig(RCC_SYSCLK_Div1);        //不分频

												/* 设置高速时钟的时钟分频 */
		RCC_PCLK2Config(RCC_HCLK_Div1);         //不分频

												/* 设置低速时钟的时钟分频 */
		RCC_PCLK1Config(RCC_HCLK_Div2);         //二分频

												/* 设置PLL时钟的输入和倍频数 */
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, pllMul);//选择HSE不分频输入，倍频PLLMUL倍

													  /* 开启 PLL */
		RCC_PLLCmd(ENABLE);

		/* 等待PLL时钟就绪 */
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{
		}

		/*选择PLL时钟作为输入 */
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

		/* 等待系统切换完成 */
		while (RCC_GetSYSCLKSource() != 0x08)
		{
		}
	}
	else              //若HSE系统开始失败，返回设置失败
	{
		return -1;
	}

	return 0;         //返回设置成功
}

/**************************************************************************** /

void NVIC_Config(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);
}
