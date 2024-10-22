/*
============================================================================
Name : 17b.c
Author : Shivam Pandey
Description :Write a program to execute ls -l | wc.
b. use dup2
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
		dup2(pipe_id[1],STDOUT_FILENO);
		close(pipe_id[1]);
		execlp("ls", "ls", "-l", NULL);
	}
	else
	{
		wait(NULL);
		close(pipe_id[1]);
		dup2(pipe_id[0],STDIN_FILENO);
		close(pipe_id[0]);
		execlp("wc","wc",NULL);
	}
	return 0;
}

