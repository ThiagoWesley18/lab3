/*
	FILE: module.c
	DESCRIPTION: implementation of module
	AUTHOR: Andre Cavalcante
	DATE: august, 2024
	LICENSE: CC BY-SA
*/

#include <limits.h>
#include <stdio.h>

#include "timer.h"

void timer_start(Timer *timer) {
	timer->start = clock();
}

void timer_stop(Timer *timer) {
	timer->stop = clock();
}

double timer_time(Timer *timer) {
	clock_t time = 0;

	if(timer->stop < 0) {
		timer->stop = -(timer->stop);
	}

	if(timer->stop < timer->start) {
		time = LONG_MAX - timer->start + timer->stop;
	} else {
		time = timer->stop - timer->start;
	}

	double time_s = (double)time / CLOCKS_PER_SEC; 

	return time_s;
}
