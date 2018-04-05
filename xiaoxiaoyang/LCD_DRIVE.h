#pragma once
#ifndef _LCD_DRIVE_H
#define _LCD_DRIVE_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stm32f1xx_hal.h>  //引脚定义
	//TET地址结构体
	typedef struct
	{
		uint16_t TFT_CMD;
		uint16_t TFT_DATA;
	} TFT_TypeDef;
	/* 使用NOR/SRAM的BANK1.SECTOR4，地址位HADDR[27,26]=11  A10作为数据命令区分割线 */
	/* 注意STM32内部会右移一位对其！ 111110=0X3E */
#define TFT_BASE        ((uint32_t)(0x6C000000 | 0x000007FE))
#define TFT             ((TFT_TypeDef *) TFT_BASE)

	/* 定义屏幕的大小 */
#define TFT_XMAX 239		//?è??TFT?????ó??
#define TFT_YMAX 319

	/* 定义颜色的宏 */
#define WHITE          0xFFFF
#define BLACK          0x0000
#define BLUE           0x001F
#define RED            0xF800
#define MAGENTA        0xF81F
#define GREEN          0x07E0
#define CYAN           0x7FFF
#define YELLOW         0xFFE0		 

	/* 定义全局变量 */
	void TFT_WriteCmd(uint16_t cmd);
	void TFT_WriteData(uint16_t dat);
	void TFT_WriteData_Color(uint16_t color);

	void TFT_Init(void);
	void TFT_SetWindow(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd);
	void TFT_ClearScreen(uint16_t color);


#ifdef __cplusplus
}
#endif


#endif 

