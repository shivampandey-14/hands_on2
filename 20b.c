/*
============================================================================
Name : 20b.c
Author : Shivam Pandey
Description :20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd=open("my_fifo",O_RDONLY,0766);
	char buffer[100];
	read(fd,buffer,sizeof(buffer));
	printf("Message recived from fifo is: %s",buffer);
	return 0;
}
