/*
============================================================================
Name : 1a.c
Author : Shivam Pandey
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
a. ITIMER_REAL
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<signal.h>
#include<sys/time.h>

void timer_handler(int signum)
{
	printf("Timer expired\n");
}
int main()
{
	struct itimerval timer;
	signal(SIGALRM,timer_handler);

	timer.it_value.tv_sec=10;
	timer.it_value.tv_usec=10;

	timer.it_interval.tv_sec=10;
	timer.it_interval.tv_usec=10;

	if(setitimer(ITIMER_REAL,&timer,NULL)==-1)
	{
		perror("Error while handling timer");
		return 1;
	}
	while(1);
	return 0;
}
