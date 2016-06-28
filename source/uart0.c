/*
* Copyright (c) 2016,
* All rights reserved.
*
* 文件名称： uart0.c
* 文件标识： 见配置管理计划书
* 摘 要： uart0源文件
*
* 当前版本： 1.0
* 作 者： vivi
* 完成日期： 2016年4月13日
* *
*/

#include "MC96F6432.h"
#include "GlobalVar.h"
#include "uart0.h"

unsigned char UART_BUFF_TX[TXDATACNT];

/***********************************************************
函数名称：void Uart0Init(void)
函数功能: 串口0初始化
入口参数：无
出口参数：无
备 注：
***********************************************************/
void Uart0Init(void)
{
	// initialize UART interface
	// UART0 : ASync. 9615bps N 8 1
	USI0CR2 = 	0
				|(0 << 7)		//0:数据寄存器空中断禁止；1:数据寄存器空中断使能
				|(0 << 6)		//0:数据发送完中断禁止；1:数据发送完中断使能
				|(0 << 5)		//0:数据接收完中断禁止；1:数据接收完中断使能
				|(0 << 4)		//0:睡眠模式下中断禁止；1:睡眠模式下中断使能
				|(0 << 3)		//0:发送单元禁止；1:发送单元使能
				|(0 << 2)		//0:接收单元禁止；1:接收单元使能
				|(1 << 1)		//0:USI0禁止；1:USI0使能
				|(0 << 0);		//0:正常异步接收采样率；1:双倍异步接收采样率
	USI0CR1 = 	0
				|(0 << 7)		//00:异步模式；01:同步模式
				|(0 << 6)		//10:IIC模式；11:SPI模式
				|(0 << 5)		//00:无校验；01:保留
				|(0 << 4)		//10:偶校验；11:奇校验
				|(0 << 3)		//000:5bit数据；001:6bit数据
				|(1 << 2)		//010:7bit数据；011:8bit数据//ORD0--0:LSB0-fisrt;1:MSB-first
				|(1 << 1)		//100~110:Reserved；111:9bit数据
				|(0 << 0);		//0:；1:   极性配置
	USI0CR2 |=  0
				|(0 << 7)		//0:数据寄存器空中断禁止；1:数据寄存器空中断使能
				|(0 << 6)		//0:数据发送完中断禁止；1:数据发送完中断使能
				|(1 << 5)		//0:数据接收完中断禁止；1:数据接收完中断使能
				|(0 << 4)		//0:睡眠模式下中断禁止；1:睡眠模式下中断使能
				|(1 << 3)		//0:发送单元禁止；1:发送单元使能
				|(1 << 2)		//0:接收单元禁止；1:接收单元使能
				|(0 << 1)		//0:USI0禁止；1:USI0使能
				|(0 << 0);		//0:正常异步接收采样率；1:双倍异步接收采样率	
	USI0CR3 = 0x00; 	// stop bit
	USI0BD = 0x45;  	// baud rate    9600N81@8MHz
	INT_UART0_RX_ENABLE;
}

void Uart0WriteOneByte(unsigned char dat)
{
	while(!(USI0ST1 & 0x80));	// wait
	USI0DR = dat;  	// write
}

void Uart0_TX()
{
	static unsigned index = 0;
	
	if (Is_Buff_Full == TRUE)
	{
		UART0_write(UART_BUFF_TX[index++]);
		if (index == TXDATACNT)
		{
			index = 0;
			Is_Buff_Full = FALSE;
		}
	}
}
