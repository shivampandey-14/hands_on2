/*
============================================================================
Name : 23.c
Author : Shivam Pandey
Description :23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21 Sept, 2024.
============================================================================
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>
int main()
{
	struct rlimit limit;
	if(getrlimit(RLIMIT_NOFILE,&limit)==0)
	{
		printf("Soft Limit %ld\n",limit.rlim_cur);
		printf("Hard Limit %ld\n",limit.rlim_max);
	}
	else
		perror("getrlimit");
	int pipe_fd[2];
	pipe(pipe_fd);
	int pipe_size=fcntl(pipe_fd[0],F_GETPIPE_SZ);
	printf("pipe buffer size: %d bytes\n",pipe_size);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return 0;
}
