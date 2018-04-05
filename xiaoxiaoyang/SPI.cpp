#include "SPI.h"

SPI_HandleTypeDef hspi1;

#define  ACCELERO_CS_LOW() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_RESET)
#define  ACCELERO_CS_HIGH() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_SET)


void spi1_init(void)
{
	GPIO_InitTypeDef gpio_init;

	//__HAL_AFIO_REMAP_SWJ_NONJTRST();
	__HAL_RCC_AFIO_CLK_ENABLE();
	__HAL_AFIO_REMAP_SWJ_NOJTAG();
	__HAL_AFIO_REMAP_SPI1_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_SPI1_CLK_ENABLE();

	//gpio_init.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	gpio_init.Pin = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
	gpio_init.Mode = GPIO_MODE_AF_PP;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio_init.Pull = GPIO_PULLDOWN;//GPIO_PULLDOWN
	//gpio_init.Alternate = SPI1_SCK_AF;
	HAL_GPIO_Init(GPIOB, &gpio_init);
	//HAL_GPIO_Init(GPIOA, &gpio_init);

	gpio_init.Pin = GPIO_PIN_15;
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOA, &gpio_init);

	hspi1.Instance = SPI1;
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;//HIGH
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 7;
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.NSS = SPI_NSS_SOFT;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.Mode = SPI_MODE_MASTER;
	//hspi1.Init.Mode = SPI_MODE_SLAVE;

	HAL_SPI_Init(&hspi1);
	ACCELERO_CS_LOW();
}

uint8_t SPI1_WriteRead(uint8_t Byte)
{
	uint8_t receivedbyte = 0;

	/* Send a Byte through the SPI peripheral */
	/* Read byte from the SPI bus */
	if (HAL_SPI_TransmitReceive(&hspi1, (uint8_t*)&Byte, (uint8_t*)&receivedbyte, 1, 2) != HAL_OK)
	{

	}

	return receivedbyte;
}

/**
* @brief  Reads a block of data from the Accelerometer.
* @param  pBuffer: pointer to the buffer that receives the data read from the Accelerometer.
* @param  ReadAddr: Accelerometer's internal address to read from.
* @param  NumByteToRead: number of bytes to read from the Accelerometer.
*/
void ACCELERO_IO_Read(uint8_t *pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead)
{
	if (NumByteToRead > 0x01)
	{
		ReadAddr |= (uint8_t)(READWRITE_CMD | MULTIPLEBYTE_CMD);
	}
	else
	{
		ReadAddr |= (uint8_t)READWRITE_CMD;
	}
	/* Set chip select Low at the start of the transmission */
	ACCELERO_CS_LOW();

	/* Send the Address of the indexed register */
	SPI1_WriteRead(ReadAddr);

	/* Receive the data that will be read from the device (MSB First) */
	while (NumByteToRead > 0x00)
	{
		/* Send dummy byte (0x00) to generate the SPI clock to ACCELEROMETER (Slave device) */
		*pBuffer = SPI1_WriteRead(DUMMY_BYTE);
		NumByteToRead--;
		pBuffer++;
	}

	/* Set chip select High at the end of the transmission */
	ACCELERO_CS_HIGH();

}

void SPI1_SetSpeed(uint8_t speed)
{
	SPI1->CR1 &= 0xFFC7;
	SPI1->CR1 |= speed;
	__HAL_SPI_DISABLE(&hspi1);
}
