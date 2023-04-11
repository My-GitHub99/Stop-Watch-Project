/*
 * stopwatch.c
 *
 *  Created on: Mar 7, 2023
 *      Author: user
 */
#include "stopwatch.h"
//timer 1 calc.
// F_CPU = 1Mhz      PreScaler =1024
// Resolution =1024/1Mhz = 1.024 x 10^-3
// compare match value for 1 second = 1s/resolution = 977
// compare match value for 60 seconds = 60/resolution = 58594

//timer 0 calc
//prescaler =8
// overflow time = (8/1Mhz) x 255 = 0.002 s= 2ms
// overflow times for 4 ms = 2

// Global Variables
extern uint8 segmentsValue[6];


void sevenSegemntConfig(void)
{
	// Decoder Pins
	DDRC|=0x0F; // enable first four pins in port C as output
	// BJT enable pins
	DDRA|= 0x3F; // enable first 6 pins in Port A as output
}


void externalInterruptConfig(void)
{
	// Intrrupt enable
		SREG|=(1<<7); // global entrrupt enable
		GICR|=(0x07<<5); // enable interrupts INT0,1,2 in interrupt module
		MCUCR|=(1<<ISC01) | (1<<ISC10) | (1<<ISC11); // set interrupt sense, falling edge for INRT0 and  rasing edge for INT1
		MCUCSR&=~(1<<6); // set interrupt sense for INT2 to falling edge
		DDRD&=~ ((1<<2) | (1<<3)); // set pins 2 and 3 in port D as input for interupts INT0,1
		DDRB&=~(1<<2); // set pins 2 in port B for intrupts INT2
}

void timer1_Config(void)
{
	TCCR1A|= (1<<FOC1A); //setting non PWM mode
	TCCR1B|=(1<<WGM12); // setting CTC mode
	TIMSK|=(1<<OCIE1A);// enable module compare interupt
	OCR1A=977; // compare match value for 1 second
	SREG|=(1<<7);
}


void timer1_Start(void)
{
	TCCR1B|=(1<<CS12) | (1<<CS10); // set prescaler to 1024, start timer
}

void timer1_Stop(void)
{
	TCCR1B=0x00; // set prescaler to 1024, start timer
}



void segmentDisplay(uint8 currentCount)
{

 PORTC=(PORTC & 0xC0)| (currentCount & 0x3F);
 }

void timer0_Config(void)
{

	TCNT0=0;
	TCCR0=(1<<FOC0) | (1<<CS01);
	TIMSK|=(1<<TOIE0);
	SREG|=(1<<7);

}

void resetClockDisplayCounts(void)
{
	for(int i=0;i<6;i++)
		{
			segmentsValue[i]=0;
		}
}



