/*
============================================================================
Name : 12.c
Author : Shivam Pandey
Description :Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
int main()
{
	pid_t pid=fork();
	if(pid==0)
	{
		printf("Child process: My PID is %d. Parent PID is %d\n", getpid(), getppid());
		sleep(2);
		printf("Child process: Sending SIGKILL to parent (PID: %d)\n", getppid());
		kill(getppid(),SIGKILL);
		sleep(2);
		printf("Child process: My new parent is PID %d (init or systemd)\n", getppid());
		while(1)
	       	{
	            sleep(1);
        	}
	}
	else
	{
		printf("Parent process: My PID is %d. Child PID is %d\n", getpid(), pid);
		while(1) 
                {
                    sleep(1);
                }
	}
	return 0;
}
