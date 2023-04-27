/*
 * test.c
 *
 *  Created on: Mar 10, 2023
 *      Author: 
 */



/*#include "stopwatch.h"

uint8 tick=0;
uint8 mutliplexSwitch=0;
 uint8 n=0;

int main()
{
	timer2_Config();
	timer1_Config();
	timer1_Start();
	sevenSegemntConfig();
	while(1)
	{
	segmentDisplay(n);

	}
}

ISR(TIMER0_OVF_vect)
{
	SREG|=(1<<7);
	tick++;
	if(tick>1)
	{
    PORTA&=~(1<<mutliplexSwitch);
		if(mutliplexSwitch<6)
		{
		mutliplexSwitch++;

		}

		else
		{
		mutliplexSwitch=0;
		}
		tick=0;
	PORTA=(1<<mutliplexSwitch);
	}
	}

ISR(TIMER1_COMPA_vect)
{
	n++;
}*/
