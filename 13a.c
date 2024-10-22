/*
============================================================================
Name : 13a.c
Author : Shivam Pandey
Description :Write two programs: first program is waiting to catch SIGSTOP signal, the second program
		will send the signal (using kill system call). Find out whether the first program is able to catch
		the signal or not.
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void signal_handler(int signum)
{
	if(signum==SIGSTOP)
	printf("process is being stoped by SIGSTOP system call");
}
int main()
{
	signal(SIGSTOP,signal_handler);
        printf("Process waiting to catch SIGINT or SIGSTOP (PID: %d).\n", getpid());
	while(1)
	{
	}
	return 0;
}

