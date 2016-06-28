
#include "sch.h"

//void Timer2_Init_1ms(void);
//void Timer2_Init_2ms(void);

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.C)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// Used to display the error code
extern tByte Error_code_G;

#ifdef	T1ms
void Timer2_Init_1ms()
{
	// initialize Timer2
	// 16bit timer, period = 1.000000mS   @4MHz        @Fx 8M
	T2CRH = 0x00;   	// timer setting High
	T2CRL = 0xA0;   	// timer setting Low      Fx/4 0x80---Fx/2 0xa0---Fx 0xc0
	T2ADRH = 0x15;  	// period count High      理论4000           实测5405是1ms      5389下500.67ms
	T2ADRL = 0x0D;  	// period count Low
	IE2 |= 0x08;    	// Enable Timer2 interrupt
//	T2CRH |= 0x80;  	// enable counter
}

void SCH_Init_T2_1ms(void) 
{
	tByte i;

	for (i = 0; i < SCH_MAX_TASKS; i++) 
	{
		SCH_Delete_Task(i);
	}
	Error_code_G = 0;  

	Timer2_Init_1ms();  	// initialize Timer2
}
   
#endif

#ifdef	T2ms
void Timer2_Init_2ms()
{
	// initialize Timer2
	// 16bit timer, period = 1.000000mS   @4MHz        @Fx 8M
	T2CRH = 0x00;   	// timer setting High
	T2CRL = 0x80;   	// timer setting Low      Fx/4 0x80---Fx/2 0xa0---Fx 0xc0
	T2ADRH = 0x15;  	// period count High      理论4000           实测5405是1ms      5389下500.67ms
	T2ADRL = 0x0D;  	// period count Low
	IE2 |= 0x08;    	// Enable Timer2 interrupt
//	T2CRH |= 0x80;  	// enable counter
}

void SCH_Init_T2_2ms(void) 
{
	tByte i;

	for (i = 0; i < SCH_MAX_TASKS; i++) 
	{
		SCH_Delete_Task(i);
	}
	Error_code_G = 0;  

	Timer2_Init_2ms();  	// initialize Timer2
}
#endif

void SCH_Start(void) 
{
	T2CRH |= 0x80;  	// enable counter
	sei();
}

void SCH_Update(void) interrupt INTERRUPT_Timer_2_Overflow  
   {
	tByte Index;
//	P21 = 0;
   // NOTE: calculations are in *TICKS* (not milliseconds)
   for (Index = 0; Index < SCH_MAX_TASKS; Index++)
      {
      // Check if there is a task at this location
      if (SCH_tasks_G[Index].pTask)
         {
         if (SCH_tasks_G[Index].Delay == 0)
            {
            // The task is due to run
            SCH_tasks_G[Index].RunMe += 1;  // Inc. the 'RunMe' flag

            if (SCH_tasks_G[Index].Period)
               {
               // Schedule regular tasks to run again
               SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
               }
            }
         else
            {
            // Not yet ready to run: just decrement the delay 
            SCH_tasks_G[Index].Delay -= 1;
            }
         }         
      }
//	P21 = 1;
   }   

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

