/*
 * main.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Ahmed Bahaa
 */

#include "stopwatch.h"

uint8 currentSevenSegementDisplay=0;
uint8 mutliplexSwitch=0;
uint8 segmentsValue[6]={0};

int main()
{
	externalInterruptConfig();
	sevenSegemntConfig();
	timer1_Config();
	timer0_Config();
	timer1_Start();
	resetClockDisplayCounts();

	for(;;)
	{
		segmentDisplay(currentSevenSegementDisplay);

	}
}
// Reset Clock Count
ISR (INT0_vect)
{
	 resetClockDisplayCounts();

}
// Pause Clock
ISR (INT1_vect)
{
	timer1_Stop();
}
// Resume Clock
ISR(INT2_vect)
{
	timer1_Config();
	timer1_Start();
}

// Clock refresh frequency 200hz (Happens Every 2ms)
ISR(TIMER0_OVF_vect)
{
	sei();
    PORTA&=~(1<<mutliplexSwitch);
		if(mutliplexSwitch<6)
		{
		mutliplexSwitch++;
		}
		else
		{
		mutliplexSwitch=0;
		}
	currentSevenSegementDisplay=segmentsValue[mutliplexSwitch];
	PORTA=(1<<mutliplexSwitch);
	}


// Counting Logic happens every 1 second
ISR(TIMER1_COMPA_vect)
{
	sei();
	segmentsValue[0]++;
	if (segmentsValue[0]==10)
	{
		segmentsValue[1]++;
		segmentsValue[0]=0;
	}
	// 60 seconds
	if (segmentsValue[1]== 6)
	{
		segmentsValue[1]=0;
		segmentsValue[2]++;
	}

	if(segmentsValue[2]==10)
	{
		segmentsValue[2]=0;
		segmentsValue[3]++;
	}

	if(segmentsValue[3]==6)
	{
		segmentsValue[4]++;
		segmentsValue[3]=0;
	}
	if(segmentsValue[4]==10)
	{
		segmentsValue[4]=0;
		segmentsValue[5]++;
	}
	if(segmentsValue[5]==10)
	{
		 resetClockDisplayCounts();
	}

}





