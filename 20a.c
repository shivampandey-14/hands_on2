/*
============================================================================
Name : 20a.c
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
#include<string.h>
int main()
{
	mkfifo("my_fifo",0766);
	int fd=open("my_fifo",O_WRONLY,0766);
	const char *message="Hello from the written process";
	write(fd, message, sizeof(char) * (strlen(message) + 1));
	close(fd);
	return 0;
}
