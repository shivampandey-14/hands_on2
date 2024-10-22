/*
============================================================================
Name : 17a.c
Author : Shivam Pandey
Description :Write a program to execute ls -l | wc.
a. use dup
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int pipe_id[2];
	pipe(pipe_id);
	int fd=fork();
	if(fd==0)
	{
		close(pipe_id[0]);
		close(STDOUT_FILENO);
		dup(pipe_id[1]);
		close(pipe_id[1]);
		execlp("ls","ls ","-l",NULL);
	}
	else
	{
		wait(NULL);
		close(pipe_id[1]);
		close(STDIN_FILENO);
		dup(pipe_id[0]);
		close(pipe_id[0]);
		execlp("wc","wc",NULL);
	}
	return 0;
}
