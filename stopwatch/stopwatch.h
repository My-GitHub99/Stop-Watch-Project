/*
 * stopwatch.h
 *
 *  Created on: Mar 7, 2023
 *      Author: Ahmed Bahaa
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <avr/io.h>
#include <avr/interrupt.h>


typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned short uint32;


void externalInterruptConfig(void);
void sevenSegemntConfig(void);
void timer1_Config(void);
void timer1_Start(void);
void timer1_Stop(void);
void timer0_Config(void); // delay 5 ms
void segmentDisplay(uint8 currentCount);
void resetClockDisplayCounts(void);


#endif /* STOPWATCH_H_ */
