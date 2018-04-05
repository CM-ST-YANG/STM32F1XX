#include "I2C.h"
#include "LED.h"



I2C_HandleTypeDef hi2c1;
UART_HandleTypeDef huart1;
void delay()
{
	int a = 10000;
	while (a--)
	{
		;
	}
}


//void OLED_Init(void)
//{
//
//	hi2c1.Instance = I2C1;
//	hi2c1.Init.ClockSpeed = 400000;
//	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
//	hi2c1.Init.OwnAddress1 = 0;
//	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
//	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
//	hi2c1.Init.OwnAddress2 = 0;
//	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
//	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLED;
//	HAL_I2C_Init(&hi2c1);
//	huart1.Instance = USART1;
//	huart1.Init.BaudRate = 115200;
//	huart1.Init.WordLength = UART_WORDLENGTH_8B;
//	huart1.Init.StopBits = UART_STOPBITS_1;
//	huart1.Init.Parity = UART_PARITY_NONE;
//	huart1.Init.Mode = UART_MODE_TX_RX;
//	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
//	HAL_UART_Init(&huart1);
//}
//
//
//void HAL_I2C_OLEDInit(I2C_HandleTypeDef* hi2c)
//{
//
//	GPIO_InitTypeDef GPIO_InitStruct;
//	if (hi2c->Instance == I2C1)
//	{
//		/* USER CODE BEGIN I2C1_MspInit 0 */
//
//		/* USER CODE END I2C1_MspInit 0 */
//
//		/**I2C1 GPIO Configuration
//		PB6     ------> I2C1_SCL
//		PB7     ------> I2C1_SDA
//		*/
//		GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
//		GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
//		GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
//		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//		/* Peripheral clock enable */
//		__I2C1_CLK_ENABLE();
//		/* USER CODE BEGIN I2C1_MspInit 1 */
//
//		/* USER CODE END I2C1_MspInit 1 */
//	}
//}


void i2c1_deinit(void)
{
	//__HAL_RCC_AFIO_CLK_DISABLE();		//开启AFIO时钟
	//__HAL_AFIO_REMAP_I2C1_DISABLE();		//重映射I2C1的IO口
	//__HAL_RCC_GPIOB_CLK_DISABLE();		//开启GPIOB时钟
	//__HAL_RCC_I2C1_CLK_DISABLE();		//开启I2C1时钟

	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8 | GPIO_PIN_9);


	hi2c1.Instance = I2C1;

	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.ClockSpeed = 100000;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	hi2c1.Init.OwnAddress1 = I2C_ADDRESS;
	hi2c1.Init.OwnAddress2 = 0xFE;

	I2C1->CCR = 0;
	I2C1->CR1 = 0;
	I2C1->CR2 = 0;
	I2C1->OAR1 = 0;
	I2C1->OAR2 = 0;
	I2C1->TRISE = 0;
	I2C1->SR1 = 0;
	I2C1->SR2 = 0;
	HAL_I2C_DeInit(&hi2c1);

	delay();
	delay();

}

void i2c1_init(void)
{
	GPIO_InitTypeDef gpio_init;
	


	i2c1_deinit();

    __HAL_RCC_AFIO_CLK_ENABLE();		//开启AFIO时钟
	__HAL_AFIO_REMAP_I2C1_ENABLE();		//重映射I2C1的IO口
	__HAL_RCC_GPIOB_CLK_ENABLE();		//开启GPIOB时钟
	__HAL_RCC_I2C1_CLK_ENABLE();		//开启I2C1时钟


	gpio_init.Pin = GPIO_PIN_8 | GPIO_PIN_9;

	gpio_init.Mode = GPIO_MODE_OUTPUT_OD;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio_init.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &gpio_init);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_Delay(100);
	for(char i = 0;i < 9;i++)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
		delay();
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
		delay();
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_Delay(100);

	//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
	//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);

	gpio_init.Pin = GPIO_PIN_8 | GPIO_PIN_9;

	gpio_init.Mode = GPIO_MODE_AF_OD;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio_init.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &gpio_init);


	hi2c1.Instance = I2C1;

	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.ClockSpeed = /*100000*/400000;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	hi2c1.Init.OwnAddress1 = I2C_ADDRESS;
	hi2c1.Init.OwnAddress2 = 0xFE;

	if (HAL_I2C_Init(&hi2c1) != HAL_OK)
	{
		asm("bkpt 255");
	}


}

uint8_t I2C1_ReadData(uint8_t Addr, uint8_t Reg)
{
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t value = -1;

	status = HAL_I2C_Mem_Read(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, &value, 1, 2);

	/* Check the communication status */
	if (status != HAL_OK)
	{
		/* Re-Initialize the BUS */

	}
	return value;
}

void I2C1_ReadMultData(uint8_t Addr, uint8_t Reg, uint8_t *value, uint8_t len)
{
	HAL_StatusTypeDef status = HAL_OK;

	status = HAL_I2C_Mem_Read(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, value, len, 2 * len);

	/* Check the communication status */
	if (status != HAL_OK)
	{
		/* Re-Initialize the BUS */

	}
}

void I2C1_WriteData(uint8_t Addr, uint8_t Reg, uint8_t Value)
{
	HAL_StatusTypeDef status = HAL_OK;

	status = HAL_I2C_Mem_Write(&hi2c1, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, &Value, 1, 2);

	/* Check the communication status */
	if (status != HAL_OK)
	{
		/* Re-Initialize the BUS */

	}
}

void MPU6050_Init(void)
{
	I2C1_WriteData(SlaveAddress, PWR_MGMT_1, 0x00);

	I2C1_WriteData(SlaveAddress, SMPLRT_DIV, 0x07);

	I2C1_WriteData(SlaveAddress, CONFIG, 0x06);

	I2C1_WriteData(SlaveAddress, GYRO_CONFIG, 0x18);

	I2C1_WriteData(SlaveAddress, ACCEL_CONFIG, 0x01);
}


void MPU6050_key(void)
{
	/*gpio_init.Pin = GPIO_PIN_8 | GPIO_PIN_9;

	gpio_init.Mode = GPIO_MODE_OUTPUT_OD;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio_init.Pull = GPIO_PULLUP;*/
	/*HAL_GPIO_Init(GPIOB, &gpio_init);*/
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_Delay(100);
	for (char i = 0;i < 9;i++)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
		delay();
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
		delay();
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_Delay(100);
}

//void OLED_INIT(void)
//{
//	HAL_Delay(100);
//	I2C1_WriteData(SlaveAddress, 0XAE, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X10, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XB0, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XC8, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X00, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X10, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X40, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X81, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XA1, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XA6, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XA8, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X3F, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XA4, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XD3, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X00, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XD5, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XF0, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XD9, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X22, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XDA, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X12, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XDB, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X20, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X8D, 0X00);
//	I2C1_WriteData(SlaveAddress, 0X14, 0X00);
//	I2C1_WriteData(SlaveAddress, 0XAF, 0X00);
//
//
//
//}
//void OLED_SETUP(unsigned char x, unsigned char y)
//{
//	I2C1_WriteData(SlaveAddress, 0xb0 + y,0x00);
//	I2C1_WriteData(SlaveAddress, ((x & 0xf0) >> 4) | 0x10,0x00);
//	I2C1_WriteData(SlaveAddress, (x & 0x0f) | 0x01,0x00);
//}
//
//void OLED_CLS()
//{
//	unsigned char m, n;
//	for (m = 0;m < 8;m++)
//	{
//		I2C1_WriteData(SlaveAddress, 0xb0 + m,0x00);		//page0-page1
//		I2C1_WriteData(SlaveAddress, 0x00,0x00);		//low column start address
//		I2C1_WriteData(SlaveAddress, 0x10,0x00);		//high column start address
//		for (n = 0;n < 128;n++)
//		{
//			I2C1_WriteData(SlaveAddress, 0x00,0x40);
//		}
//	}
//}
//
//void OLED_fill()
//{
//	unsigned char m, n;
//	for (m = 0;m < 8;m++)
//	{
//		I2C1_WriteData(SlaveAddress, 0xb0 + m, 0x00);		//page0-page1
//		I2C1_WriteData(SlaveAddress, 0x00, 0x00);		//low column start address
//		I2C1_WriteData(SlaveAddress, 0x10, 0x00);		//high column start address
//		for (n = 0;n < 128;n++)
//		{
//			I2C1_WriteData(SlaveAddress, 0x00, 0xff);
//		}
//	}
//}
//
//void OLED_ShowStr(unsigned char x, unsigned char y, const char ch[], unsigned char TextSize)
//{
//	unsigned char c = 0, i = 0, j = 0;
//	switch (TextSize)
//	{
//	case 1:
//	{
//		while (ch[j] != '\0')
//		{
//			c = ch[j] - 32;
//			if (x > 126)
//			{
//				x = 0;
//				y++;
//			}
//			OLED_SETUP(x, y);
//			for (i = 0;i < 6;i++)
//				I2C1_WriteData(SlaveAddress, F6x8[c][i],0x40);
//			x += 6;
//			j++;
//		}
//	}break;
//	case 2:
//	{
//		while (ch[j] != '\0')
//		{
//			c = ch[j] - 32;
//			if (x > 120)
//			{
//				x = 0;
//				y++;
//			}
//			OLED_SETUP(x, y);
//			for (i = 0;i < 8;i++)
//				I2C1_WriteData(SlaveAddress, F8X16[c * 16 + i],0x40);
//			OLED_SETUP(x, y+1);
//			for (i = 0;i < 8;i++)
//				I2C1_WriteData(SlaveAddress, F8X16[c * 16 + i + 8],0x40);
//			x += 8;
//			j++;
//		}
//	}break;
//	}
//}