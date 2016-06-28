#include "MC96F6432.h"
#include "LCD.h"
#include "GlobalVar.h"

unsigned char	code	LCD_SEG_TAB[] =
{
	0xd7,	//0
	0x50,	//1
	0xb5,	//2
	0xf1,	//3
	0x72,	//4
	0xe3,	//5
	0xe7,	//6
	0x51,	//7
	0xf7,	//8
	0xf3,	//9
	0x00,	//off
};

void lcd_allOn(void)
{
	unsigned char i;
	for(i=2;i<29;i++)	
	{
		LCD_SEG(i)=0xff;
	}
}
void lcd_allOff(void)
{
	unsigned char i;
	for(i=2;i<10;i++)	
	{
		LCD_SEG(i)=0x00;
	}
}

void LCD_init()
{
	// initialize LCD
	// Frame freq. = 61.035156Hz
	LCDCRH = 0x01;  	// LCD control High
	LCDCRL = 0x0D;  	// LCD control Low
	LCDCCR = 0x00;  	// LCD contrast
//	lcd_allOff();
}

unsigned char HEX2BCD(unsigned char hexdata)
{
	unsigned char i = hexdata;
	hexdata = ((hexdata/10)<<4) | ((hexdata)%10);
	return hexdata;
}

	/*
	   DM1         DM2
	abcd|efgh	abcd|efgh
	wei1 wei2	wei3 wei4
	*/
void DisplayMatrix(unsigned char x,unsigned char y,unsigned char bflash)
{
	unsigned char DM1 = x;
	unsigned char DM2 = y;
	DM1 = HEX2BCD(DM1);
	DM2 = HEX2BCD(DM2);
	if(TimeFlag^T500ms)
	{
		if(bflash == 1)
		{
			DM1 = 0xAA;			
		}
		else if(bflash == 2)
		{
			DM2 = 0xAA;
		}
		else if(bflash == 3)
		{
			DM1 = 0xAA;	
			DM2 = 0xAA;			
		}
	}
	LCD_SEG(2) &= 0x08;
	LCD_SEG(2) |= LCD_SEG_TAB[DM1>>4];
	LCD_SEG(3) = LCD_SEG_TAB[(DM1>>4)]>>4;	
	LCD_SEG(4) = LCD_SEG_TAB[DM1&0x0f];
	LCD_SEG(5) = LCD_SEG_TAB[(DM1&0x0f)]>>4;
	LCD_SEG(6) = LCD_SEG_TAB[DM2>>4];
	LCD_SEG(7) = LCD_SEG_TAB[(DM2>>4)]>>4;
	LCD_SEG(8) = LCD_SEG_TAB[DM2&0x0f];
	LCD_SEG(9) = LCD_SEG_TAB[(DM2&0x0f)]>>4;
}