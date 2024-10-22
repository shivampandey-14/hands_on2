/*
============================================================================
Name : 1c.c
Author : Shivam Pandey
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10 micro second
c. ITIMER_PROF
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<errno.h>
void timer_hand(int sysnum)
{
	printf("Timer over\n");
}

int main()
{
	struct itimerval timer;

	signal(SIGPROF,timer_hand);

	timer.it_value.tv_sec=10;
	timer.it_value.tv_usec=10;

	timer.it_interval.tv_sec=10;
	timer.it_interval.tv_usec=10;

	if(setitimer(ITIMER_PROF,&timer,NULL)==-1)
	{
		perror("error while setting timer");
		return 1;
	}
	while(1);
	return 0;
}

