/*
============================================================================
Name : 1b.c
Author : Shivam Pandey
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10 micro second
b. ITIMER_VIRTUAL
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
	printf("time out\n");
}
int main()
{

	struct itimerval timer;
	
	signal(SIGVTALRM,timer_handler);

	timer.it_value.tv_sec=10;
	timer.it_value.tv_usec=10;

	timer.it_interval.tv_sec=10;
	timer.it_interval.tv_usec=10;

	if(setitimer(ITIMER_VIRTUAL,&timer,NULL)==-1)
	{
		perror("Error opening the file");
		return 1;
	}

	while(1);
	return 0;
}


