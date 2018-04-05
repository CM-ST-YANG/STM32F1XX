#include <stm32f1xx_hal.h>
#include "LED.h"
#include "PWM.h"
#include "UART1.h"
#include "UART2.h"
#include "PRINT.h"
#include "I2C.h"
#include "CALLBACK.h"
#include "reset.h"
#include "GTA0.h"
#include "PWR.h"
#include "DAC.h"
#include "KEY.h"
#include "DMA.h"
#include "ssd1306.h"


int i,j;

uint8_t val1[10];
uint8_t val2[10];
uint8_t val=0;
uint8_t SPI;
uint8_t key;
uint16_t dac_value=3000;
int8_t speed[2] = { 1,0 };
int8_t accel[4] = { 10,10,10,10 };
int8_t angle[13];
double ssd=1;
uint8_t MPU6050[13] = { ACCEL_CONFIG,ACCEL_XOUT_H,ACCEL_XOUT_L,ACCEL_YOUT_H,ACCEL_YOUT_L,ACCEL_ZOUT_H,ACCEL_ZOUT_L,GYRO_XOUT_H,GYRO_XOUT_L,GYRO_YOUT_H,GYRO_YOUT_L,GYRO_ZOUT_H	,GYRO_ZOUT_L };
extern int receive1[10];
extern int receive2[10];
extern I2C_HandleTypeDef hi2c1;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel1;
#ifdef __cplusplus
extern "C"
#endif

//void SysTick_Handler(void)
//{
//	HAL_IncTick();
//	HAL_SYSTICK_IRQHandler();
//}


//void delay()
//{
//	int a = 10000;
//	while (a--)
//	{
//		;
//	}
//}

int main(void)
{
//	SystemCoreClockUpdate();
//	HAL_Init();
//	OLED_Init();
//	MX_GPIO_Init();
//	uint8_t res = SSD1306_Init();
//	while (1)
//	{
//		SSD1306_GotoXY(10, 27);
//		SSD1306_Puts("OLED inited", &Font_7x10, 1);
//		SSD1306_GotoXY(10, 52);
//		SSD1306_Puts("Lutsai Alexander", &Font_7x10, 1);
//		SSD1306_UpdateScreen();
//
//	}
	 //display
	/*OLED_INIT();
	i2c1_init();

	while (1)
	{
		OLED_showdouble(0, 4, ssd);*/
		//HAL_Delay(2);
		//OLED_ShowStr(0, 4, "i am your father", 2);			
	//}
	
}
		//电压分频
		
		//DAC_init();
		
		/*HAL_DAC_SetValue(&hdac, DACx_CHANNEL, DAC_ALIGN_12B_R, dac_value);
		
		HAL_DAC_Start(&hdac, DACx_CHANNEL);
		KEY_GPIO_Init();
		LED_GDB_INIT();
		while (1)
		{
			if (KEY1_StateRead() == KEY_UP&&val==0)
			{
				HAL_GPIO_WritePin(GPIOC, LED, GPIO_PIN_RESET);
				val == 1;
			}*/
			/*else if (KEY1_StateRead() == KEY_DOWN && val == 1)
			{
				HAL_GPIO_WritePin(GPIOC, LED, GPIO_PIN_SET);
				val == 0;
			}*/
				
				//	dac_value = 25;
				//HAL_DAC_SetValue(&hdac, DACx_CHANNEL, DAC_ALIGN_12B_R, dac_value);
		//}
	
      		//LED模块
		/*LED_GDB_INIT();
		for (;;)




		{
			HAL_GPIO_WritePin(GPIOC, LED, GPIO_PIN_SET);
			HAL_Delay(i);
			HAL_GPIO_WritePin(GPIOC, LED, GPIO_PIN_RESET);
			HAL_Delay(i);

		}
		*/
		
	
	
	
	//PWM模块
	  
	    //PWM_init();
		//i = 2000;
		//while (1)
		//{
		//	for (;i < 10000;i++)
		//	{
		//		set_pwm_val(__PWM_PA6, i);
		//		if (i > TIM3->CNT)
		//		{
		//			j = 1;
		//		}
		//		else
		//		{
		//			j = 0;
		//		}
		//	}
		//	for (;i > 0;i--)
		//	{
		//		set_pwm_val(__PWM_PA6, i);
		//		if (i > TIM3->CNT)
		//		{
		//			j = 1;
		//		}
		//		else
		//		{
		//			j = 0;
		//		}
		//	}
		//}
	
		
		
		
		//串口

		/*uart1_init();
		uart2_init(); */  //值都存在receive里
		/*for (i = 0;i <= 9;i++)
		{
			val1[i] = receive1[i];
			val2[i] = receive2[i];
		}*/
		/*uart_cmp1(ch1);
		uart_cmp2(ch2);*/
		//while (1);
		
		//I2C通信

		/*i2c1_init();
		MPU6050_Init();*/
		//while (1)    //模拟手动
		//{
		//	if (I2C1_ReadData(SlaveAddress, ..CONFIG) != -1)
		//	{
		//		if (I2C1_ReadData(SlaveAddress, CONFIG) != 6)
		//		{
		//			MPU6050_Init();
		//			asm("bkpt 255");
		//		}
		//	}
		//	else
		//	{
		//		//__HAL_I2C_ENABLE(hi2c);
		//		//__HAL_RCC_I2C1_CLK_DISABLE();
		//		i2c1_init();
		//		MPU6050_Init();
		//	}
		//	if (val == 0x68)
		//	{
		//		/*for (i = 0;i <= 12;i++)
		//		{
		//			angle[i] = I2C1_ReadData(SlaveAddress, MPU6050[i]);
		//		}*/
		//		angle[1] = (int8_t)I2C1_ReadData(SlaveAddress, MPU6050[1]);
		//		angle[3] = (int8_t)I2C1_ReadData(SlaveAddress, MPU6050[3]);
		//		SPEED_A(&angle[1], &speed[0], &accel[0], &accel[1]);
		//		SPEED_A(&angle[3], &speed[1], &accel[2], &accel[3]);
		//	}		
		//		val = I2C1_ReadData(SlaveAddress, WHO_AM_I);
		//	
		//	}


	   //I2C1_WriteData(uint8_t Addr, uint8_t Reg, uint8_t Val1[9]); //写入函数示例
       
        //SPI通信
  /* spi1_init();
	while (1)
	{
		SPI = SPI1_WriteRead(speed[0]);

	}*/
	
    //待机模式

//HAL_GPIO_WritePin(GPIOC, LED, GPIO_PIN_RESET);
//HAL_Delay(2000);
//standbymode();
	

		//电机驱动
	
		//OLCD
	
	

