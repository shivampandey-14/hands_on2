/*
============================================================================
Name : 10.c
Author : Shivam Pandey
Description :Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void signal_handler(int signum)
{
	if(signum==SIGSEGV) 
	{
        	printf("Caught SIGSEGV (Segmentation Fault).\n");
       		exit(1);
    	}	
       	else if(signum == SIGINT) 
    	{
        	printf("Caught SIGINT (Interrupt Signal).\n");
    	} 	
	else if (signum == SIGFPE) 
    	{
        	printf("Caught SIGFPE (Floating-Point Exception).\n");
        	exit(1);
    	}
}
int main()
{
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	sa.sa_handler=signal_handler;
	sigaction(SIGINT,&sa,NULL);
	sigaction(SIGSEGV,&sa,NULL);
	sigaction(SIGFPE,&sa,NULL);
	printf("Signal handlers are set. Press Ctrl+C to trigger SIGINT.\n");
	int *p=NULL;
	//*p=19;
//	int x = 1 / 0;
	while(1)
		sleep(1);
	return 0;
}
