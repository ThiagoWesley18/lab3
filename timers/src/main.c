/*
	FILE: main.c
	DESCR: entry point of the program
	AUTHOR: Andre Cavalcante
	DATE: November, 2024
	LICENSE: CC BY-SA
*/

#include <stdio.h>
#include <stdlib.h>

#include <timer.h>

void msleep(long ms) {
	long sec = ms / 1000;
	ms = ms % 1000;
	struct timespec req;
	req.tv_sec = sec;
	req.tv_nsec = ms * 1000000;
	nanosleep(&req, NULL);
}

//int main(int argc, char *argv[])
int main()
{
	printf("Timers!\n");

	Timer t1, t2;

	timer_start(&t1);
	for(int i=0; i < 10; i++) {
		timer_start(&t2);
		for(int j=0; j < 9800; j++) {
			for(int k=0; k < 53000; k++);
		}
		timer_stop(&t2);
		printf("Elapsed Time: %f s\n", timer_time(&t2));
	}
	timer_stop(&t1);
	printf("Elapsed Time: %f s\n", timer_time(&t1));
	
	printf("Bye!\n");
	return EXIT_SUCCESS;
}
