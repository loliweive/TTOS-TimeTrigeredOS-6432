/*
* Copyright (c) 2016,
* All rights reserved.
*
* 文件名称： usart0.h
* 文件标识： 见配置管理计划书
* 摘 要： 串口配置头文件，在使用usart0的C文件中包含
*
* 当前版本： 1.0
* 作 者： vivi
* 完成日期： 2016年4月13日
* *
*/
#ifndef _uart0_h_
#define _uart0_h_
#include "globalvar.h"
#ifndef TRUE
#define FALSE 0
#define TRUE (!FALSE)
#endif

//2个byte做帧头，2个byte做帧尾，1个数据
#ifndef TXDATACNT
#define TXDATACNT (4+1)
#endif
#define Is_Buff_Full BYTEBIT.BIT0 

//Global Variable
extern unsigned char UART_BUFF_TX[];

//Global functions
extern unsigned char UART0_read();
extern void UART0_WriteOneByte(unsigned char dat);
extern void UART0_Init();  
extern void UART0_TX();

#endif