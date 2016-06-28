//======================================================
// interrupt routines
//======================================================

#include	"MC96F6432.h"
#include "GlobalVar.h"
#include "uart0.h"


void INT_USI0_Rx() interrupt 9
{
	// USI0 Rx interrupt
	// TODO: add your code here
	static unsigned char ByteCnt = 0;
	if(USI0ST1 & 0x20)
	{
		UART_BUFF_TX[ByteCnt] = USI0DR;
		if(++ByteCnt == TXDATACNT)
		{
			ByteCnt = 0;
			Is_Buff_Full = TRUE;
		}
	}
}

