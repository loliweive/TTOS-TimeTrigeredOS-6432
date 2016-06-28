#include "IOTest.h"
#include "key.h"
#include "LCD.H"
#include "GlobalVar.h"

void IO_Test(void)
{
	LCD_SEG(2) ^= 0X08;
	TimeFlag ^= T500ms;
	if(TimeFlag^T500ms)
	{
		LCD_SEG(2) &= (~0X08);
		LED0 = LEDOFF;
	}
	else
	{
		LCD_SEG(2) |= 0X08;
		LED0 = LEDON;
	}
}