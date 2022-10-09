/*
 * TIMER.c
 *
 * Created: 9/5/2022 10:18:04 PM
 *  Author: Lenovo
 */ 
#include "timer.h"
#include "../../Utilities/BIT_MATH.h"

void TIMER_init(void)
{
	TCCR0 = 0x00; //chose normal mode
}
void TIMER_delay(uint16_t millisec)
{
	uint16_t Numoverflows,TimerInitial;
	
	double Tmaxdelay,Ttick;
	
	uint32_t overFlowcnt=0;
	
	//max delay 256 micro second
	
	//at 1MHz no prescaler
	
	// 256 prescaler
	Ttick = 256.0/1000.0;     
	//ms    Ttick = Presc/FCPU
	Tmaxdelay= 65.536;
	 //ms		Tmaxdelay = Ttick * 2^8
	if(millisec<Tmaxdelay)
	{
		TimerInitial = (Tmaxdelay-millisec)/Ttick;
		Numoverflows = 1;
		
		}
		else if(millisec == (int)Tmaxdelay)
		{
		TimerInitial=0;
		Numoverflows=1;
		}
		else
		{
		Numoverflows = ceil((double)millisec/Tmaxdelay);
		TimerInitial = (1<<8) - ((double)millisec/Ttick)/Numoverflows;
		
	}
	TCNT0 = TimerInitial;
	TCCR0 |= (1<<2); //set 256 prescaler
	
	while(overFlowcnt<Numoverflows)
	{
		//busy wait
		while(GET_BIT(TIFR,0)==0);
		//clear overflow flag
		SET_BIT(TIFR,0);
		//increment counter
		overFlowcnt++;
	}
	//Timer stop
	TCCR0 = 0x00;
}