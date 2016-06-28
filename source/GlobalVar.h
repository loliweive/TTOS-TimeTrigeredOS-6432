/*
* Copyright (c) 2016,
* All rights reserved.
*
* 文件名称： GlobalVar.h
* 文件标识： 见配置管理计划书
* 摘 要： 全局变量和全局函数声明头文件
*
* 当前版本： 1.0
* 作 者： vivi
* 完成日期： 2016年4月13日
* *
*/

#ifndef _GlobalVar_h_
#define _GlobalVar_h_

/*------------------*
*   8位变量位映射   *
*------------------*/
typedef struct BYTE_BIT
{
    unsigned BIT0:1;
    unsigned BIT1:1;
    unsigned BIT2:1;
    unsigned BIT3:1;
    unsigned BIT4:1;
    unsigned BIT5:1;
    unsigned BIT6:1;
    unsigned BIT7:1;
}BYTEBIT;

/*------------------*
*   16位变量位映射  *
*------------------*/
typedef struct WORD_BIT
{
    unsigned BIT0:1;
    unsigned BIT1:1;
    unsigned BIT2:1;
    unsigned BIT3:1;
    unsigned BIT4:1;
    unsigned BIT5:1;
    unsigned BIT6:1;
    unsigned BIT7:1;
   
    unsigned BIT8:1;
    unsigned BIT9:1;
    unsigned BIT10:1;
    unsigned BIT11:1;
    unsigned BIT12:1;
    unsigned BIT13:1;
    unsigned BIT14:1;
    unsigned BIT15:1;
}WORDBIT;

//extern BYTEBIT BitFlag;
#define T500ms 0x01
#define LEDOFF	1
#define	LEDON	0

#define UART_ADDR	0x01
#define READ_UART_ADDR ((P0&0x01)|((P0&0x02)<<1))

#ifdef	MC96F6432
//中断使能失能宏
#define	INT_ALL_ENABLE				(IE |= 0X80)
#define	INT_ALL_DISABLE				(IE &= ~0X80)

#define	INT_EXT0_7_ENABLE			(IE |= 0X20)
#define	INT_EXT0_7_DISABLE			(IE &= ~0X20)
#define	INT_EXT8_ENABLE				(IE1 |= 0X01)
#define	INT_EXT8_DISABLE			(IE1 &= ~0X01)
#define	INT_EXT10_ENABLE			(IE |= 0X01)
#define	INT_EXT10_DISABLE			(IE &= ~0X01)
#define	INT_EXT11_ENABLE			(IE |= 0X02)
#define	INT_EXT11_DISABLE			(IE &= ~0X02)
#define	INT_EXT12_ENABLE			(IE1 |= 0X20)
#define	INT_EXT12_DISABLE			(IE1 &= ~0X20)

#define	INT_IIC0_ENABLE				(IE1 |= 0X04)
#define	INT_IIC0_DISABLE			(IE1 &= ~0X04)
#define	INT_IIC1_ENABLE				(IE |= 0X04)
#define	INT_IIC1_DISABLE			(IE &= ~0X04)
#define	INT_SPI2_ENABLE				(IE3 |= 0X02)
#define	INT_SPI2_DISABLE			(IE3 &= ~0X02)

#define	INT_UART0_TX_ENABLE			(IE1 |= 0x10)
#define	INT_UART0_TX_DISABLE		(IE1 &= ~0x10)
#define	INT_UART0_RX_ENABLE			(IE1 |= 0x08)
#define	INT_UART0_RX_DISABLE		(IE1 &= ~0x08)
#define	INT_UART1_TX_ENABLE			(IE |= 0X10)
#define	INT_UART1_TX_DISABLE		(IE &= ~0X10)
#define	INT_UART1_RX_ENABLE			(IE |= 0X08)
#define	INT_UART1_RX_DISABLE		(IE &= ~0X08)

#define	INT_TIMER0_MATCH_ENABLE		(IE2 |= 0X02)
#define	INT_TIMER0_MATCH_DISABLE	(IE2 &= ~0X02)
#define	INT_TIMER0_OVERFLOW_ENABLE	(IE2 |= 0X01)
#define	INT_TIMER0_OVERFLOW_DISABLE	(IE2 &= ~0X01)
#define	INT_TIMER1_ENABLE			(IE2 |= 0X04)
#define	INT_TIMER1_DISABLE			(IE2 &= ~0X04)
#define	INT_TIMER2_ENABLE			(IE2 |= 0X08)
#define	INT_TIMER2_DISABLE			(IE2 &= ~0X08)
#define	INT_TIMER3_ENABLE			(IE2 |= 0X10)
#define	INT_TIMER3_DISABLE			(IE2 &= ~0X10)
#define	INT_TIMER4_ENABLE			(IE2 |= 0X20)
#define	INT_TIMER4_DISABLE			(IE2 &= ~0X20)

#define	INT_BIT_ENABLE				(IE3 |= 0X10)
#define	INT_BIT_DISABLE				(IE3 &= ~0X10)
#define	INT_WDT_ENABLE				(IE3 |= 0X08)
#define	INT_WDT_DISABLE				(IE3 &= ~0X08)
#define	INT_WT_ENABLE				(IE3 |= 0X04)
#define	INT_WT_DISABLE				(IE3 &= ~0X04)

#define	INT_ADC_ENABLE				(IE3 |= 0X01)
#define	INT_ADC_DISABLE				(IE3 &= ~0X01)

//中断序号
#define	INTERRUPT_EXT_10		0
#define	INTERRUPT_EXT_11		1
#define	INTERRUPT_IIC_1			2
#define	INTERRUPT_UART_1_RX		3
#define	INTERRUPT_UART_1_TX		4
#define	INTERRUPT_EXT_0_7		5
#define	INTERRUPT_EXT_8			6
#define	INTERRUPT_IIC_0			8
#define	INTERRUPT_UART_0_RX		9
#define	INTERRUPT_UART_0_TX		10
#define	INTERRUPT_EXT_12		11
#define	INTERRUPT_T0_Overflow	12
#define	INTERRUPT_T0_Match		13
#define	INTERRUPT_T1_Match		14
#define	INTERRUPT_T2_Match		15
#define	INTERRUPT_T3_Match		16
#define	INTERRUPT_T4			17
#define	INTERRUPT_ADC			18
#define	INTERRUPT_SPI2			19
#define	INTERRUPT_Watch_Timer	20
#define	INTERRUPT_WDT			21
#define	INTERRUPT_BIT			22

#endif

//======================================================
// Function and global variables definition
//======================================================

void Peripheral_Init();





#endif