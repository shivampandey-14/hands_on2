/*
============================================================================
Name : 21a.c
Author : Shivam Pandey
Description :Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int main()
{
	mkfifo("fifo1",0766);
	mkfifo("fifo2",0766);
	int fd=open("fifo1",O_WRONLY);
	if(fd==-1) 
	{
        	perror("open fifo1 failed");
        	exit(EXIT_FAILURE);
	}
	const char *message="HI from process 1";
	write(fd,message,strlen(message)+1);
	
	int fd2=open("fifo2",O_RDONLY);
	if(fd2==-1)
       	{
        	perror("open fifo1 failed");
        	exit(EXIT_FAILURE);
	}
	char buffer[100];
	read(fd2,buffer,sizeof(buffer));
	printf("Message recived from process 2 : %s\n",buffer);
	close(fd2);
	close(fd);
	return 0;
}
