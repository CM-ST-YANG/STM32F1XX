#include "PWR.h"




void standbymode(void)
{
	
	__HAL_RCC_PWR_CLK_ENABLE();//使能时钟

	
	HAL_PWR_EnableBkUpAccess();

	
	//__HAL_RCC_BACKUPRESET_FORCE();
	//__HAL_RCC_BACKUPRESET_RELEASE();

	
	HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);//失能引脚

	
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);//清理唤醒标志

	
	HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);//重使能

	
	HAL_PWR_EnterSTANDBYMode();//进入待机模式
}
