//======================================================
//		device		: MC96F6432(44 pin)
//		version		: Ver1.0
//		date		: 2011-03-30
//		compiler	: Keil-C
//		author		: Ma, Nakwon
//======================================================

#include	<intrins.h>

#ifndef		_MC96F6432_
#define		_MC96F6432_

sfr			P0			= 0x80;			// P0 Data Register
	sbit	P00			= 0x80;
	sbit	P01			= 0x81;
	sbit	P02			= 0x82;
	sbit	P03			= 0x83;
	sbit	P04			= 0x84;
	sbit	P05			= 0x85;
	sbit	P06			= 0x86;
	sbit	P07			= 0x87;

sfr			P0IO		= 0xA1;			// P0 Direction Register
sfr			P0OD		= 0x91;			// P0 Open-drain Selection Register
sfr			P0PU		= 0xAC;			// P0 Pull-up Resistor Selection Register
sfr			P0DB		= 0xDE;			// P0 Debounce Enable Register

sfr			P1			= 0x88;			// P1 Data Register
	sbit	P10			= 0x88;
	sbit	P11			= 0x89;
	sbit	P12			= 0x8A;
	sbit	P13			= 0x8B;
	sbit	P14			= 0x8C;
	sbit	P15			= 0x8D;
	sbit	P16			= 0x8E;
	sbit	P17			= 0x8F;
	
sfr			P1IO		= 0xB1;			// P1 Direction Register
sfr			P1OD		= 0x92;			// P1 Open-drain Selection Register
sfr			P1PU		= 0xAD;			// P1 Pull-up Resistor Selection Register
sfr			P15DB		= 0xDF;			// P1/P5 Debounce Enable Register

sfr			P2			= 0x90;			// P2 Data Register
	sbit	P20			= 0x90;
	sbit	P21			= 0x91;
	sbit	P22			= 0x92;
	sbit	P23			= 0x93;
	sbit	P24			= 0x94;
	sbit	P25			= 0x95;
	sbit	P26			= 0x96;
	sbit	P27			= 0x97;

sfr			P2IO		= 0xB9;			// P2 Direction Register
sfr			P2OD		= 0x93;			// P2 Open-drain Selection Register
sfr			P2PU		= 0xAE;			// P2 Pull-up Resistor Selection Register

sfr			P3			= 0x98;			// P3 Data Register
	sbit	P30			= 0x98;
	sbit	P31			= 0x99;
	sbit	P32			= 0x9A;
	sbit	P33			= 0x9B;
	sbit	P34			= 0x9C;
	sbit	P35			= 0x9D;
	sbit	P36			= 0x9E;
	sbit	P37			= 0x9F;

sfr			P3IO		= 0xC1;			// P3 Direction Register
sfr			P3PU		= 0xAF;			// P3 Pull-up Resistor Selection Register

sfr			P4			= 0xA0;			// P4 Data Register
	sbit	P40			= 0xA0;
	sbit	P41			= 0xA1;
	sbit	P42			= 0xA2;
	sbit	P43			= 0xA3;
	
sfr			P4IO		= 0xC9;			// P4 Direction Register
sfr			P4OD		= 0x94;			// P4 Open-drain Selection Register
sfr			P4PU		= 0xA3;			// P4 Pull-up Resistor Selection Register

sfr			P5			= 0xB0;			// P5 Data Register
	sbit	P50			= 0xB0;
	sbit	P51			= 0xB1;
	sbit	P52			= 0xB2;
	sbit	P53			= 0xB3;
	sbit	P54			= 0xB4;
	sbit	P55			= 0xB5;

sfr			P5IO		= 0xD1;			// P5 Direction Register
sfr			P5PU		= 0x95;			// P5 Pull-up Resistor Selection Register

 // Port Function Selection Register
sfr			P0FSRL		= 0xD2;			//Port Function Selection Low Register 0
sfr			P0FSRH		= 0xD3;			//Port Function Selection High Register 0
sfr			P1FSRL		= 0xD4;			//Port Function Selection Low Register 1
sfr			P1FSRH		= 0xD5;			//Port Function Selection High Register 1
sfr			P2FSRL		= 0xD6;			//Port Function Selection Low Register 2
sfr			P2FSRH		= 0xD7;			//Port Function Selection High Register 2
sfr			P3FSR		= 0xEE;			//Port Function Selection Register 3
sfr			P4FSR		= 0xEF;			//Port Function Selection Register 4
sfr			P5FSR		= 0xFF;			//Port Function Selection Register 5

// System Oscillator, Reset Control
sfr			SCCR		= 0x8A;			// System Clock Control Register
sfr			OSCCR		= 0xC8;			// Oscillator Control Register
sfr			BITCNT		= 0x8C;			// Basic Interval Timer Counter Register
sfr			BITCR		= 0x8B;			// BIT Clock Control Register
sfr			RSTFR		= 0xE8;			// Reset Flag Register
sfr			PCON		= 0x87;			// Power Control Register
sfr			LVRCR		= 0xD8;			// Low Voltage Reset Control Register
sfr			LVICR		= 0x86;			// Low Voltage Indicator Control Register

//  Watch Dog Timer Control 
sfr			WDTDR		= 0x8E;			// Watch Dog Timer Data Register
sfr			WDTCNT		= 0x8E;			// Watch Dog Timer Counter Register
sfr			WDTCR		= 0x8D;			// Watch Dog Timer Control Register

//  Watch Timer Control
sfr			WTDR		= 0x89;			// Watch Timer Data Register
sfr			WTCNT		= 0x89;			// Watch Timer Counter Register
sfr			WTCR		= 0x96;			// Watch Timer Control Register

// Interrupt Control
sfr			IE3			= 0xAB;			// Interrupt Enable Register 3
sfr			IE2			= 0xAA;			// Interrupt Enable Register 2
sfr			IE1			= 0xA9;			// Interrupt Enable Register 1
sfr			IE			= 0xA8;			// Interrupt Enable Register 0
sfr			IP			= 0xB8;			// Interrupt Priority Register 0
sfr			IP1			= 0xF8;			// Interrupt Priority Register 1

sfr			EIFLAG0		= 0xC0;			// External Interrupt Flag Register 0
sfr			EIPOL0L		= 0xA4;			// External Interrupt Polarity Low Register 0
sfr			EIPOL0H		= 0xA5;			// External Interrupt Polarity High Register 0
sfr			EIFLAG1		= 0xA6;			// External Interrupt Flag Register 1
sfr			EIPOL1		= 0xA7;			// External Interrupt Polarity Register 1

// TIMER 0 Control
sfr			T0CR		= 0xB2;			// Timer 0 Mode Control Register
sfr			T0CNT		= 0xB3;			// Timer 0 Counter Register
sfr			T0DR		= 0xB4;			// Timer 0 Data Register
sfr			T0CDR		= 0xB4;			// Timer 0 Capture Data Register

// TIMER 1 Control
sfr			T1CRL		= 0xBA;			// Timer 1 Control Low Register
sfr			T1CRH		= 0xBB;			// Timer 1 Control HIgh Register
sfr			T1ADRL		= 0xBC;			// Timer 1 A Data Low Register
sfr			T1ADRH		= 0xBD;			// Timer 1 A Data High Register
sfr			T1BDRL		= 0xBE;			// Timer 1 B Data Low Register
sfr			T1BDRH		= 0xBF;			// Timer 1 B Data High Register

// TIMER 2 Control
sfr			T2CRL		= 0xC2;			// Timer 2 Control Low Register
sfr			T2CRH		= 0xC3;			// Timer 2 Control HIgh Register
sfr			T2ADRL		= 0xC4;			// Timer 2 A Data Low Register
sfr			T2ADRH		= 0xC5;			// Timer 2 A Data High Register
sfr			T2BDRL		= 0xC6;			// Timer 2 B Data Low Register
sfr			T2BDRH		= 0xC7;			// Timer 2 B Data High Register

// TIMER 3 Control
#define		T3CR		*(volatile unsigned char xdata *) 0x1000	// Timer 3 Control Register
#define		T3CNT		*(volatile unsigned char xdata *) 0x1001	// Timer 3 Counter Register
#define		T3DR		*(volatile unsigned char xdata *) 0x1001	// Timer 3 Data Register
#define		T3CAPR		*(volatile unsigned char xdata *) 0x1001	// Timer 3 Capture Data Register

// TIMER 4 Control
#define		T4CR		*(volatile unsigned char xdata *) 0x1002	// Timer 4 Control Register
#define		T4PCR1		*(volatile unsigned char xdata *) 0x1003	// Timer 4 PWM Control Register 1
#define		T4PCR2		*(volatile unsigned char xdata *) 0x1004	// Timer 4 PWM Control Register 2
#define		T4PCR3		*(volatile unsigned char xdata *) 0x1005	// Timer 4 PWM Control Register 3

#define		T4ISR		*(volatile unsigned char xdata *) 0x1006	// Timer 4 Interrupt Status Register
#define		T4MSK		*(volatile unsigned char xdata *) 0x1007	// Timer 4 Interrupt Mask Register
#define		T4PPRL		*(volatile unsigned char xdata *) 0x1008	// Timer 4 PWM Period Low Register
#define		T4PPRH		*(volatile unsigned char xdata *) 0x1009	// Timer 4 PWM Period High Register
#define		T4ADRL		*(volatile unsigned char xdata *) 0x100A	// Timer 4 PWM A Duty Low Register
#define		T4ADRH		*(volatile unsigned char xdata *) 0x100B	// Timer 4 PWM A Duty High Register
#define		T4BDRL		*(volatile unsigned char xdata *) 0x100C	// Timer 4 PWM B Duty Low Register
#define		T4BDRH		*(volatile unsigned char xdata *) 0x100D	// Timer 4 PWM B Duty High Register
#define		T4CDRL		*(volatile unsigned char xdata *) 0x100E	// Timer 4 PWM C Duty Low Register
#define		T4CDRH		*(volatile unsigned char xdata *) 0x100F	// Timer 4 PWM C Duty High Register
#define		T4DLYA		*(volatile unsigned char xdata *) 0x1010	// Timer 4 PWM A Delay Register
#define		T4DLYB		*(volatile unsigned char xdata *) 0x1011	// Timer 4 PWM B Delay Register
#define		T4DLYC		*(volatile unsigned char xdata *) 0x1012	// Timer 4 PWM C Delay Register
#define		T4DR		*(volatile unsigned char xdata *) 0x1013	// Timer 4 Data Register
#define		T4CAPR		*(volatile unsigned char xdata *) 0x1014	// Timer 4 Capture Data Register
#define		T4CNT		*(volatile unsigned char xdata *) 0x1015	// Timer 4 Counter Register

// BUZZER Control
sfr			BUZCR		= 0x97;			// BUZZER Control Register
sfr			BUZDR		= 0x8F;			// BUZZER Data Register

// SPI(SIO) Control
sfr			SPICR		= 0xB5;			// SPI Control Register
sfr			SPIDR		= 0xB6;			// SPI Data Register
sfr			SPISR		= 0xB7;			// SPI Pre-scaler Register

// ADC Contol
sfr			ADCCRL		= 0x9C;			// A/D Converter Control Low Register
sfr			ADCCRH		= 0x9D;			// A/D Converter Control High Register
sfr			ADCDRL		= 0x9E;			// A/D Converter Data Low Register
sfr			ADCDRH		= 0x9F;			// A/D Converter Data High Register

// (UART + SPI + I2C) Control
sfr			USI0CR1		= 0xD9;			// USI0 Control Register 1
sfr			USI0CR2		= 0xDA;			// USI0 Control Register 2
sfr			USI0CR3		= 0xDB;			// USI0 Control Register 3
sfr			USI0CR4		= 0xDC;			// USI0 Control Register 4
sfr			USI0SAR		= 0xDD;			// USI0 Slave Address Register
sfr			USI0ST1		= 0xE1;			// USI0 Status Register 1
sfr			USI0ST2		= 0xE2;			// USI0 Status Register 2
sfr			USI0BD		= 0xE3;			// USI0 Baud Rate Generation Register
sfr			USI0SDHR	= 0xE4;			// USI0 SDA Hold Time Register
sfr			USI0DR		= 0xE5;			// USI0 Data Register
sfr			USI0SCLR	= 0xE6;			// USI0 SCL Low Period Register
sfr			USI0SCHR	= 0xE7;			// USI0 SCL High Period Register

sfr			USI1CR1		= 0xE9;			// USI1 Control Register 1
sfr			USI1CR2		= 0xEA;			// USI1 Control Register 2
sfr			USI1CR3		= 0xEB;			// USI1 Control Register 3
sfr			USI1CR4		= 0xEC;			// USI1 Control Register 4
sfr			USI1SAR		= 0xED;			// USI1 Slave Address Register
sfr			USI1ST1		= 0xF1;			// USI1 Status Register 1
sfr			USI1ST2		= 0xF2;			// USI1 Status Register 2
sfr			USI1BD		= 0xF3;			// USI1 Baud Rate Generation Register
sfr			USI1SDHR	= 0xF4;			// USI1 SDA Hold Time Register
sfr			USI1DR		= 0xF5;			// USI1 Data Register
sfr			USI1SCLR	= 0xF6;			// USI1 SCL Low Period Register
sfr			USI1SCHR	= 0xF7;			// USI1 SCL High Period Register

// LCD COntrol
sfr			LCDCRL		= 0x99;			// LCD Driver Control Low Register
sfr			LCDCRH		= 0x9A;			// LCD Driver Control High Register
sfr			LCDCCR		= 0x9B;			// LCD Contrast Control Register

// Flash Memory Control
sfr			FSADRH		= 0xFA;			// Flash Sector Address High Register
sfr			FSADRM		= 0xFB;			// Flash Sector Address Middle Register
sfr			FSADRL		= 0xFC;			// Flash Sector Address Low Register
sfr			FIDR		= 0xFD;			// Flash Identification Register
sfr			FMCR		= 0xFE;			// Flash Mode Control Register

sfr			ACC			= 0xE0;
sfr			B			= 0xF0;
sfr			PSW			= 0xD0;

//sfr		CY			= 0xD7;			// carry 
//sfr		AC			= 0xD6;			// aux carry
//sfr		F0			= 0xD5;			// user difinable flag0
//sfr		RS1			= 0xD4;			// register bank select
//sfr		RS0			= 0xD3;			//
//sfr		OV			= 0xD2;			// overflow
//sfr		F1			= 0xD1;			// user difinable flag1
//sfr		P			= 0xD0;			// parity

sfr			SP			= 0x81;
sfr			DPL			= 0x82;
sfr			DPH			= 0x83;
sfr			DPL1		= 0x84;
sfr			DPH1		= 0x85;
sfr			EO			= 0xA2;			// EXTENDED OPERATION REGISTER

#endif									//_MC96F6432_

#define		cli()		do{IE &= ~0x80;}while(0)
#define		sei()		do{IE |=  0x80;}while(0)
#define		NOP			_nop_()
