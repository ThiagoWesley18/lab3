/*
	FILE: main.c
	DESCR: entry point of the program
	AUTHOR: Andre Cavalcante
	DATE: august, 2024
	LICENSE: CC BY-SA
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "monitor.h"
#include "uthread.h"
#include "yfthread.h"
#include "display.h"

//int main(int argc, char *argv[])
int main()
{
	printf("t,v,w,y1,y2,y3\n");

    pthread_t uthr;
    pthread_t ythr;
    pthread_t display_thr;
    pthread_attr_t attr_uthr, attr_ythr, attr_display;
    struct sched_param param_uthr, param_ythr, param_display;

    SharedMemo shared, *shm = &shared;
    
    monitor_init(shm);

    // Inicializar atributos das threads
    pthread_attr_init(&attr_uthr);
    pthread_attr_init(&attr_ythr);
    pthread_attr_init(&attr_display);

    // Definir política de escalonamento para SCHED_RR
    pthread_attr_setschedpolicy(&attr_uthr, SCHED_RR);
    pthread_attr_setschedpolicy(&attr_ythr, SCHED_RR);
    pthread_attr_setschedpolicy(&attr_display, SCHED_RR);

    // Definir prioridades baseadas nos períodos das threads
    param_uthr.sched_priority = 90; // Prioridade alta para thread com menor período
    param_ythr.sched_priority = 80; // Prioridade média
    param_display.sched_priority = 70; // Prioridade baixa para thread com maior período

    pthread_attr_setschedparam(&attr_uthr, &param_uthr);
    pthread_attr_setschedparam(&attr_ythr, &param_ythr);
    pthread_attr_setschedparam(&attr_display, &param_display);

    pthread_create(&uthr, &attr_uthr, uthread, shm);
    pthread_create(&ythr, &attr_ythr, yfthread, shm);
    pthread_create(&display_thr, &attr_display, display_print, shm);
    
    pthread_join(ythr, NULL);
    pthread_join(uthr, NULL);
    pthread_join(display_thr, NULL);
    
    monitor_destroy(shm);

    return EXIT_SUCCESS;
}