#include "UART2.h"

UART_HandleTypeDef huart2;
uint8_t receive2[10], transmit2[10];

extern "C" void USART2_IRQHandler();
/**
* @brief 初始化串口4
* @param none
* @note none
* @retval none
*/

void uart2_init(void)
{
	GPIO_InitTypeDef gpio_init;

	HAL_NVIC_SetPriority(USART2_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);

	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	gpio_init.Pin = GPIO_PIN_2;
	gpio_init.Mode = GPIO_MODE_AF_PP;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio_init.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &gpio_init);

	gpio_init.Pin = GPIO_PIN_3;
	gpio_init.Mode = GPIO_MODE_AF_INPUT;
	HAL_GPIO_Init(GPIOA, &gpio_init);

	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = USART_WORDLENGTH_8B;
	huart2.Init.StopBits = USART_STOPBITS_1;
	huart2.Init.Parity = USART_PARITY_NONE;
	huart2.Init.Mode = USART_MODE_TX_RX;
	huart2.Instance = USART2;

	HAL_UART_Init(&huart2);
	HAL_UART_Receive_IT(&huart2, receive2, 1);
}

/**
* @brief 串口4发送字符串
* @param *b：字符串数组指针
* @note none
* @retval none
*/
void uart2_send(const char *b)
{
	char len = strlen(b);
	HAL_UART_Transmit(&huart2, (uint8_t *)b, len, len * 2);
}

void UART2_Handler(void)
{
	HAL_UART_Receive_IT(&huart2, receive2, 1);
}

void USART2_IRQHandler()
{
	HAL_UART_IRQHandler(&huart2);
}

