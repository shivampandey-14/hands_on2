/*
============================================================================
Name : 22.c
Author : Shivam Pandey
Description :22. Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>

int main()
{
	if(mkfifo("my_fifo", 0666)==-1 && errno!=EEXIST) {
        	perror("mkfifo");
        	exit(EXIT_FAILURE);
    	}
	int fd=open("my_fifo",O_RDONLY|O_NONBLOCK);
	if(fd==-1)
       	{
        	perror("open");
        	exit(EXIT_FAILURE);
    	}
	fd_set read_fd;
	FD_ZERO(&read_fd);
	FD_SET(fd,&read_fd);

	struct timeval time;
	time.tv_sec=10;
	time.tv_usec=0;
	char buffer[100];
	int ret=select(fd+1,&read_fd,NULL,NULL,&time);
	if(ret==-1)
       	{
       		 perror("select");
       		 close(fd);
       		 exit(EXIT_FAILURE);
    	}
	else if(FD_ISSET(fd,&read_fd))
	{
		ret = read(fd, buffer, sizeof(buffer) - 1);
		if (ret==-1)
	       	{
            		perror("read");
        	}
	       	else if (ret == 0) 
		{
        	    printf("No more data. FIFO writer has closed the connection.\n");
       		 }
	       	else
	       	{
            		buffer[ret] = '\0';  // Null-terminate the string
            		printf("Received data: %s\n", buffer);
        	}
	}
	close(fd);
	return 0;
}








