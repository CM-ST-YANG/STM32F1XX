
#include "GTA0.h"

void SPEED_A(int8_t *angle, int8_t *speed1, int8_t *accel1,int8_t *accel2)
{

	if (*angle > 20)
	{
		*speed1 += *accel1;
		HAL_Delay(300);
		if (*speed1 > 90)
		{
			*speed1 = 80;
			*accel1 = 10;
		}
		*accel1 += 2;
		*accel2 = 10;
	}
	else if (*angle < -20)
	{
		*speed1 -= *accel2;
		HAL_Delay(300);
		if (*speed1 < -90)
		{
			*speed1 = -80;
			*accel2 = 10;
		}
		*accel2 += 2;
		*accel1 = 10;
	}

}