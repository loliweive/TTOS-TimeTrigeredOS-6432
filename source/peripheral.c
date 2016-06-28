//======================================================
// peripheral setting routines
//======================================================

#include	"MC96F6432.h"
#include	"uart0.h"

void WT_init()
{
	// initialize Watch timer
	WTCR = 	0           //WT控制寄存器
			|(1 << 7)		//0Disable,1Enable
			|(0 << 4)		//0WTI no generation,1WTI generation
			|(0 << 3)		//00Fwck/2^7,01Fwck/2^13
			|(0 << 2)		//10Fwck/2^14,11Fwck/(2^14*(7bit WTDR+1))
			|(0 << 1)		//00Fsub,01Fx/256
			|(1 << 0);	//10Fx/128,11Fx/64
	WTDR = 0x03;    	// set duty
	WTDR |= 0x80;    	// clear WT
}

void clock_init()
{
	// internal RC clock (8.000000MHz)
	OSCCR = 0x20;   	// Set Int. OSC
	SCCR = 0x00;    	// Use Int. OSC
}

void port_init()
{
	// initialize ports
	P0IO = 0xFF;    	// direction
	P0PU = 0x00;    	// pullup
	P0OD = 0x00;    	// open drain
	P0DB = 0x00;    	// bit7~6(debounce clock), bit5~0=P07~02 debounce
	P0   = 0x00;    	// port initial value
	
	P1IO = 0xFF;    	// direction
	P1PU = 0x00;    	// pullup
	P1OD = 0x00;    	// open drain
	P15DB = 0x00;   	// debounce : P54, 52, 17, 16, 12, 11
	P1   = 0x00;    	// port initial value
	
	P2IO = 0x02;    	// direction              P21做输出，测试任务
	P2PU = 0x0f;    	// pullup
	P2OD = 0x00;    	// open drain
	P2   = 0x00;    	// port initial value
	
	P3IO = 0xFF;    	// direction
	P3PU = 0x00;    	// pullup
	P3   = 0x00;    	// port initial value
	
	P4IO = 0x02;    	// direction
	P4PU = 0x00;    	// pullup
	P4OD = 0x00;    	// open drain
	P4   = 0x00;    	// port initial value
	
	P5IO = 0xFF;    	// direction
	P5PU = 0x00;    	// pullup
	P5   = 0x00;    	// port initial value
	
	// Set port functions
	P0FSRH = 0x00;  	// P0 selection High
	P0FSRL = 0x00;  	// P0 selection Low
	P1FSRH = 0x55;  	// P1 selection High
	P1FSRL = 0x17;  	// P1 selection Low
	P2FSRH = 0x0F;  	// P2 selection High
	P2FSRL = 0x00;  	// P2 selection Low
	P3FSR = 0xFF;   	// P3 selection
	P4FSR = 0x0A;   	// P4 selection
	P5FSR = 0x00;   	// P5 selection
}

void Peripheral_Init()
{
	port_init();    	// initialize ports
	clock_init();   	// initialize operation clock
//	LCD_init();     	// initialize LCD
	WT_init();      	// initialize Watch timer
	UART0_init();
}
