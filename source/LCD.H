#ifndef _LCD_H_
#define _LCD_H_

#define LCD_SEG(x) 	(*((volatile unsigned char xdata*)(x)))             //x=0-29(SEG0---SEG29)

#define     SEG0    *(volatile unsigned char xdata *) 0x00
#define     SEG1    *(volatile unsigned char xdata *) 0x01
#define     SEG2    *(volatile unsigned char xdata *) 0x02
#define     SEG3    *(volatile unsigned char xdata *) 0x03
#define     SEG4    *(volatile unsigned char xdata *) 0x04
#define     SEG5    *(volatile unsigned char xdata *) 0x05
#define     SEG6    *(volatile unsigned char xdata *) 0x06
#define     SEG7    *(volatile unsigned char xdata *) 0x07
#define     SEG8    *(volatile unsigned char xdata *) 0x08
#define     SEG9    *(volatile unsigned char xdata *) 0x09
#define     SEG10   *(volatile unsigned char xdata *) 0x0A
#define     SEG11   *(volatile unsigned char xdata *) 0x0B
#define     SEG12   *(volatile unsigned char xdata *) 0x0C
#define     SEG13   *(volatile unsigned char xdata *) 0x0D
#define     SEG14   *(volatile unsigned char xdata *) 0x0E
#define     SEG15   *(volatile unsigned char xdata *) 0x0F
#define     SEG16   *(volatile unsigned char xdata *) 0x10
#define     SEG17   *(volatile unsigned char xdata *) 0x11
#define     SEG18   *(volatile unsigned char xdata *) 0x12
#define     SEG19   *(volatile unsigned char xdata *) 0x13
#define     SEG20   *(volatile unsigned char xdata *) 0x14
#define     SEG21   *(volatile unsigned char xdata *) 0x15
#define     SEG22   *(volatile unsigned char xdata *) 0x16
#define     SEG23   *(volatile unsigned char xdata *) 0x17
#define     SEG24   *(volatile unsigned char xdata *) 0x18
#define     SEG25   *(volatile unsigned char xdata *) 0x19
#define     SEG26   *(volatile unsigned char xdata *) 0x1A


extern void DisplayMatrix(unsigned char x,unsigned char y,unsigned char bflash);
extern void LCD_init();








#endif