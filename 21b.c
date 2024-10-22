/*
============================================================================
Name : 21b.c
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
        int fd=open("fifo1",O_RDONLY);
	if(fd==-1)
       	{
        	perror("open fifo1 failed");
        	exit(EXIT_FAILURE);
    	}
	char buffer[100];
        read(fd,buffer,sizeof(buffer));
        printf("Message recived from process 1 : %s\n",buffer);

        const char *message="HI from process 2";
        int fd2=open("fifo2",O_WRONLY);
	if(fd2==-1)
       	{
        	perror("open fifo2 failed");
        	exit(EXIT_FAILURE);
    	}
	write(fd2, message, strlen(message) + 1);
        close(fd2);
	close(fd);
        return 0;
}

