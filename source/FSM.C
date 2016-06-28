#include "FSM.H"
#include "key.h"
#include "LCD.h"
#include "uart0.h"
#include "GlobalVar.h"

unsigned char hour;
unsigned char minute;
unsigned char second;
unsigned char alarmhour;
unsigned char alarmminute;
unsigned char alarmsecond;
unsigned char tickmilisecond;
unsigned char ticksecond;
unsigned char bibitime;
static unsigned char time;
bit bsecondstart;
bit bsecondstop;
bit balarm;
//还有一个超状态-----------在闹铃时间等于当前时间时，不管状态机处于何种状态，均跳转到此超状态，
//超状态结束后回到原始状态

void CalTime()
{
	if(++time == 100)
	{
		time = 0;
		if(++second == 60)
		{
			second = 0;
			if((bibitime != 0)&&(balarm == 1))
			{
				bibitime--;//////////////
			}
			if(++minute == 60)
			{
				minute = 0;
				if(++hour == 24)
				{
					hour = 0;
				}
			}
		}
	}
}

bit CalAlarm()
{
	if(bibitime == 0)
	{
		balarm = 0;
		return 1;
	}
	else if(balarm == 1)
	{
		DisplayMatrix(alarmhour,alarmminute,3);
		if(KeyValue == (KEYA_VALUE | KEY_DOWN))
		{
			bibitime = 0;
			KeyValue = KEY_NULL;
			return 1;
		}
		if(KeyValue == (KEYB_VALUE | KEY_DOWN))
		{
			KeyValue = KEY_NULL;
			bibitime = 0;
			return 1;
		}		
		return 0;
	}
	else if((alarmhour == hour)&&(alarmminute == minute))
	{
		balarm = 1;
		return 0;
	}
	return 1;
}

void FSM_Update(void)
{
	static unsigned char WatchState;
	static unsigned char timecnt10ms;

//	P21 = 0;
	minute = UART0_read();
	GetKey(&KeyValue);
	CalTime();
	if (CalAlarm() == 1)
	{
		switch(WatchState)
		{
			case WATCHINIT:
			WatchState = DISPLAYTIME;
			break;

			case DISPLAYTIME:
			DisplayMatrix(hour,minute,0);
			if(KeyValue == (KEYA_VALUE | KEY_DOWN))
			{
				WatchState = DISPLAYALARM;
			}
			if(KeyValue == (KEYB_VALUE | KEY_DOWN))
			{
				WatchState = SETHOUR;
			}
			break;
			
			case DISPLAYALARM:
			DisplayMatrix(alarmhour,alarmminute,0);
			if(++timecnt10ms > 250)
			{
				WatchState = DISPLAYTIME;
				timecnt10ms = 0;
			}
			if(KeyValue == (KEYA_VALUE | KEY_DOWN))
			{
				WatchState = DISPLAYSEC;
				timecnt10ms = 0;
			}
			if(KeyValue == (KEYB_VALUE | KEY_DOWN))
			{
				WatchState = SETALARMHOUR;
				timecnt10ms = 0;
			}
			break;
			
			case DISPLAYSEC:
			if(bsecondstart)
			{
				if(++tickmilisecond == 100)
				{
					tickmilisecond = 0;
					if(++ticksecond == 60)
					{
						ticksecond = 0;
					}
				}
			}
			DisplayMatrix(ticksecond,tickmilisecond,0);
			if((++timecnt10ms > 250 )&&(bsecondstop == 0))
			{
				if(bsecondstart == 0)
				{
					WatchState = DISPLAYTIME;
				}
				timecnt10ms = 0;
			}
			if(KeyValue == (KEYA_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				bsecondstart = !bsecondstart;
				bsecondstop = 1;
			}
			if(KeyValue == (KEYB_VALUE | KEY_DOWN))
			{
				tickmilisecond = 0;
				ticksecond = 0;
				timecnt10ms = 0;
				bsecondstart = 0;
				bsecondstop = 0;
			}
			break;
			
			case SETHOUR:
			DisplayMatrix(hour,minute,1);
			if(++timecnt10ms > 250 )
			{
				WatchState = DISPLAYTIME;
				timecnt10ms = 0;
			}
			if(KeyValue == (KEYA_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				if(++hour == 24) hour = 0;			
			}
			if(KeyValue == (KEYB_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				WatchState = SETMINUTE;
			}
			break;
			
			case SETMINUTE:
			DisplayMatrix(hour,minute,2);
			if(++timecnt10ms > 250 )
			{
				WatchState = DISPLAYTIME;
				timecnt10ms = 0;
			}
			if(KeyValue == (KEYA_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				if(++minute == 60) minute = 0;
				second = 0;
			}
			if(KeyValue == (KEYB_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				WatchState = DISPLAYTIME;
			}
			break;
			
			case SETALARMHOUR:
			DisplayMatrix(alarmhour,alarmminute,1);
			if(++timecnt10ms > 250 )
			{
				WatchState = DISPLAYTIME;
				timecnt10ms = 0;
			}
			if(KeyValue == (KEYA_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				if(++alarmhour == 24) hour = 0;			
			}
			if(KeyValue == (KEYB_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				WatchState = SETALARMMINUTE;
			}		
			break;
			
			case SETALARMMINUTE:
			DisplayMatrix(alarmhour,alarmminute,2);
			if(++timecnt10ms > 250 )
			{
				WatchState = DISPLAYTIME;
				timecnt10ms = 0;
			}
			if(KeyValue == (KEYA_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				if(++alarmminute == 60) alarmminute = 0;			
			}
			if(KeyValue == (KEYB_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				WatchState = SETBIBITIME;
			}
			break;

			case SETBIBITIME:
			DisplayMatrix(0x00,bibitime,2);
			if(++timecnt10ms > 250 )
			{
				WatchState = DISPLAYTIME;
				timecnt10ms = 0;
			}
			if(KeyValue == (KEYA_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				if(++bibitime == 60) bibitime = 0;			
			}
			if(KeyValue == (KEYB_VALUE | KEY_DOWN))
			{
				timecnt10ms = 0;
				WatchState = DISPLAYALARM;
			}
			break;
			
			default:
				
			break;
			
		}
	}
//	P21 = 1;
}