#include "PRINT.h"

static char buffer[100];

static char stradd[10];



void usart2_ptint(char *str, int data, int mode)

{

#ifdef USE_PRINTF

	usart2_send(str);

	itoa((int)data, buffer, mode);

	usart2_send(buffer);

	usart2_send("\n");

#endif // USE_PRINTF

}



int tenpow(int len)

{

	int data = 1;

	while (len--)

		data = 10 * data;

	return data;

}



void usart2_ptintf(char *str, float data, int len)

{

#ifdef USE_PRINTF



	usart2_send(str);

	itoa((int)data, buffer, 10);

	if (len)

	{

		strncat(buffer, ".", 1);

		itoa((int)((data - (int)data) * tenpow(len)), stradd, 10);

		strncat(buffer, stradd, 10);

	}

	usart2_send(buffer);

	usart2_send("\n");



#endif // USE_PRINTF

}



/*void _printf(char *fmt, ...)

{

#ifdef USE_PRINTF

va_list ap;



va_start(ap, fmt);

vsprintf(buffer, fmt, ap);

va_end(ap);

usart2_send(buffer);

#endif // USE_PRINTF

}*/



/*

#pragma import(__use_no_semihosting)



struct __FILE

{

int handle;

};



FILE __stdout;



_sys_exit(int x)

{

x = x;

}

_ttywrch(int ch)

{

ch = ch;

}



int fputc(int ch, FILE *f)

{

HAL_USART_Transmit(&husart2,(uint8_t *)(&ch),1,50);

return ch;

}*/


