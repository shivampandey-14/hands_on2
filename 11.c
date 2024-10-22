/*
============================================================================
Name : 11.c
Author : Shivam Pandey
Description :Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signal_handler(int signum)
{
	printf("SIGINT ignored! Press Ctrl+C again after 5 seconds to exit.\n");
}
int main()
{
	struct sigaction sa;
	sa.sa_handler=ignore_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	sigaction(SIGINT,&sa,NULL);
	printf("SIGINT is being ignored for 5 seconds. Press Ctrl+C now.\n");
    	sleep(5);
	sa.sa_handler=SIG_DFL;
	sigaction(SIGINT, &sa, NULL);
	printf("SIGINT reset to default action. Press Ctrl+C again to terminate the program.\n");
	while (1)
       	{
     	   sleep(1);
    	}
	return 0;
}
