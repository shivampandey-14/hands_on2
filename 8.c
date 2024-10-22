/*
============================================================================
Name : 8.c
Author : Shivam Pandey
Description :Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

// Signal handler function
void signal_handler(int sig) {
    switch (sig) {
        case SIGSEGV:
            printf("Caught SIGSEGV: Segmentation Fault\n");
            exit(1);  // Exit after handling the signal
        case SIGINT:
            printf("Caught SIGINT: Interrupt from keyboard (Ctrl+C)\n");
            break;
        case SIGFPE:
            printf("Caught SIGFPE: Floating Point Exception\n");
            exit(1);  // Exit after handling the signal
        case SIGALRM:
            printf("Caught SIGALRM: Alarm signal\n");
            break;
        case SIGVTALRM:
            printf("Caught SIGVTALRM: Virtual timer alarm\n");
            break;
        case SIGPROF:
            printf("Caught SIGPROF: Profiling timer alarm\n");
            break;
        default:
            printf("Caught signal %d\n", sig);
            break;
    }
}
void triger_sigfpe()
{
	int z=5/0;
	(void)z;
}
void sigsegv()
{
	int *p=NULL;
	*p=10;
}
void triger_alarm()
{
	alarm(2);
}
void setup_timer(int t)
{
	struct itimerval timer;
	timer.it_value.tv_sec=1;
	timer.it_value.tv_usec=0;
	timer.it_interval.tv_sec=0;
	timer.it_interval.tv_usec=0;

	setitimer(t,&timer,NULL);
}


int main()
{
	signal(SIGSEGV, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGFPE, signal_handler);
	signal(SIGALRM, signal_handler);
	signal(SIGVTALRM, signal_handler);
	signal(SIGPROF, signal_handler);

	printf("Press ctrl+C to trigger SIGINT...\n");
	triger_alarm();

	printf("Triggering SIGALRM using setitimer in 2 seconds...\n");
    	setup_timer(ITIMER_REAL);

	printf("Triggering SIGVTALRM using setitimer in 2 seconds...\n");
	setup_timer(ITIMER_VIRTUAL);
	
	printf("Triggering SIGPROF using setitimer in 2 seconds...\n");
    	setup_timer(ITIMER_PROF);

	while (1) 
	{
        	pause();
    	}
	return 0;
}
