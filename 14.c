/*
============================================================================
Name : 14.c
Author : Shivam Pandey
Description :Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
	int pipe_fd[2];
	pipe(pipe_fd);
	int fd=fork();
	char write_buff[]="Hi i am Shivam Pandey";
	char read_buff[100];
	if(fd==0)
	{
		close(pipe_fd[1]);
		read(pipe_fd[0],read_buff,sizeof(read_buff));
		printf("Received message: %s\n",read_buff);
		close(pipe_fd[0]);
	}
	else
	{
		close(pipe_fd[0]);
                write(pipe_fd[1],write_buff,strlen(write_buff)+1);
                close(pipe_fd[1]);
		wait(NULL);
        }
	return 0;
}

