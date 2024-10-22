/*
============================================================================
Name : 18.c
Author : Shivam Pandey
Description :Write a program to find out total number of directories on the pwd. execute ls -l | grep ^d | wc ? Use only dup2.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int pipe1[2],pipe2[2];
	pipe(pipe1);
	pipe(pipe2);
	int fd1=fork();
	if(fd1==0)
	{
		close(pipe1[0]);
		dup2(pipe1[1],STDOUT_FILENO);
		close(pipe1[1]);
		execlp("ls","ls","-l",NULL);
	}
	int fd2=fork();
	if(fd2==0)
	{
		close(pipe1[1]);
		dup2(pipe1[0],STDIN_FILENO);
		close(pipe1[0]);
		close(pipe2[0]);
		dup2(pipe2[1],STDOUT_FILENO);
		close(pipe2[1]);
		execlp("grep","grep","^d",NULL);
	
	}
	wait(NULL);
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[1]);
	dup2(pipe2[0],STDIN_FILENO);

	close(pipe2[0]);
	execlp("wc","wc","-l",NULL);
	return 0;
}

