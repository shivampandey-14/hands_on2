/*
============================================================================
Name : 13b.c
Author : Shivam Pandey
Description :Write two programs: first program is waiting to catch SIGSTOP signal, the second program
		will send the signal (using kill system call). Find out whether the first program is able to catch
		the signal or not.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include<sys/wait.h>
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        	exit(1);
	}
	pid_t pid_target=atoi(argv[1]);
	printf("Sending SIGSTOP to process %d\n", pid_target);
	kill(pid_target,SIGSTOP);
	sleep(2);
	printf("Sending SIGCONT to process %d\n", pid_target);
	kill(pid_target,SIGCONT);
	return 0;
}
