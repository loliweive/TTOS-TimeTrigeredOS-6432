#include "mc96f6432.h"

#ifndef __key_h_
#define __key_h_


//IO define
#define KEYA	(P1 & 0x01)		//由硬件上的连接关系来决定	
#define	KEYB	(P1 & 0x02)		//由硬件上的连接关系来决定
#define	KEYC	(P1 & 0x03)		//由硬件上的连接关系来决定
#define	KEYD	(P1 & 0x04)		//由硬件上的连接关系来决定

//定义按键按下后对应key的状态值		
#define KEYA_VALUE	0x0e	//00001110
#define KEYB_VALUE	0X0d	//00001101
#define KEY2_VALUE	0x0b	//00001011
#define KEY3_VALUE	0X07	//00000111
#define KEY_NULL	0x0f

//定义按键返回值（按下，长按，连按，释放）
#define KEY_DOWN		0X80
#define	KEY_LONG		0X40
#define	KEY_CONTINUE	0X20
#define	KEY_UP			0X10

//定义长按及双击的tick数
#define	KEY_LONG_PERIOD		100			//长按tick数100
#define KEY_CONTINUE_PERIOD	25			//累加tick数25

//定义IO口
//#define KeyPort P2
//sbit IO_Key0 = KeyPort^0;
//sbit IO_Key1 = KeyPort^1;
//sbit IO_Key2 = KeyPort^2;
//sbit IO_Key3 = KeyPort^3;
sbit IO_KeyA = P2^0;
sbit IO_KeyB = P1^0;

#define LEDPort P4
sbit LED0 = LEDPort^0;
//sbit LED1 = LEDPort^1;
//sbit LED2 = LEDPort^2;
//sbit LED3 = LEDPort^3;

//定义按键状态
#define KEY_STATE_INIT		0			//初始化
#define	KEY_STATE_WOBBLE	1           //消抖
#define	KEY_STATE_PRESS		2			//按键按下
#define	KEY_STATE_LONG		3			//按键长按
#define	KEY_STATE_CONTINUE	4			//按键双击
#define	KEY_STATE_RELEASE	5			//按键释放



//extern void Key_Update(void);
extern void GetKey(unsigned char *pKeyValue);
extern unsigned char KeyValue;

#endif
