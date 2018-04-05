#include "UART1.h"

UART_HandleTypeDef huart1;
uint8_t receive1[10], transmit1[10];

extern "C" void USART1_IRQHandler();
/**
* @brief 初始化串口4
* @param none
* @note none
* @retval none
*/

void uart1_init(void)
{
	GPIO_InitTypeDef gpio_init;  //引脚配置

	HAL_NVIC_SetPriority(USART1_IRQn, 4, 0); //串口号，优先级
	HAL_NVIC_EnableIRQ(USART1_IRQn);     //使能串口

	//__HAL_RCC_AFIO_CLK_ENABLE();
	__HAL_AFIO_REMAP_USART1_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	gpio_init.Pin = GPIO_PIN_6;   //IO口配置
	gpio_init.Mode = GPIO_MODE_AF_PP;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio_init.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &gpio_init);

	gpio_init.Pin = GPIO_PIN_7;
	gpio_init.Mode = GPIO_MODE_AF_INPUT;
	HAL_GPIO_Init(GPIOB, &gpio_init);

	huart1.Init.BaudRate = 115200;       //串口配置
	huart1.Init.WordLength = USART_WORDLENGTH_8B;
	huart1.Init.StopBits = USART_STOPBITS_1;
	huart1.Init.Parity = USART_PARITY_NONE;
	huart1.Init.Mode = USART_MODE_TX_RX;
	huart1.Instance = USART1;

	HAL_UART_Init(&huart1);
	HAL_UART_Receive_IT(&huart1, receive1, 1);
}

/**
* @brief 串口4发送字符串
* @param *b：字符串数组指针
* @note none
* @retval none
*/
void uart1_send(const char *b)
{
	char len = strlen(b);
	HAL_UART_Transmit(&huart1, (uint8_t *)b, len, len * 2);
}

void UART1_Handler(void)
{
	HAL_UART_Receive_IT(&huart1, receive1, 1);
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&huart1);
}


