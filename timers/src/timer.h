/*
	FILE: timer.h
	DESCRIPTION: public definitions of timer
	AUTHOR: Andre Cavalcante
	DATE: August, 2024
	LICENSE: CC BY-SA
*/

#ifndef TIMER_H__
#define TIMER_H__

#include <time.h>

typedef struct timer {
	clock_t start, stop;
} Timer;

void timer_start(Timer *timer);
void timer_stop(Timer *timer);
double timer_time(Timer *timer);

#endif //TIMER_H__