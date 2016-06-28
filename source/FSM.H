#ifndef _FSM_H_
#define _FSM_H_

#define WATCHINIT		0
#define DISPLAYTIME		1
#define	DISPLAYALARM    2
#define	DISPLAYSEC		3
#define	SETHOUR			4
#define SETMINUTE		5
#define SETALARMHOUR	6
#define	SETALARMMINUTE	7
#define	SETBIBITIME		8

#define FLASH 	1
#define NFLASH	!FLASH


extern void FSM_Update(void);















#endif