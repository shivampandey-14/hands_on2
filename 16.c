/*
============================================================================
Name : 16.c
Author : Shivam Pandey
Description :Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int pipe_to_child[2];
	int pipe_to_parent[2];
	char parent_msg[]="Hello from Parent!";
	char child_msg[]="Hello from Child!";
	char read_buffer[100];
	pipe(pipe_to_parent);
	pipe(pipe_to_child);
	int fd=fork();
	if(fd>0)
	{
		close(pipe_to_child[0]);
		close(pipe_to_parent[1]);
		write(pipe_to_child[1],parent_msg,strlen(parent_msg)+1);
		close(pipe_to_child[1]);
		read(pipe_to_parent[0],read_buffer,sizeof(read_buffer));
		printf("Parent recived %s\n",read_buffer);
		close(pipe_to_parent[0]);
		wait(NULL);
	}
	else
	{
		close(pipe_to_parent[0]);
		close(pipe_to_child[1]);
		write(pipe_to_parent[1],child_msg,strlen(child_msg)+1);
		close(pipe_to_parent[1]);
		read(pipe_to_child[0],read_buffer,sizeof(read_buffer));
		printf("Child recived %s \n",read_buffer);
		close(pipe_to_child[0]);

	}
	return 0;
}

