/*
============================================================================
Name : 19c.c
Author : Shivam Pandey
Description :Create a FIFO file by
c. mknod system call
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <sys/sysmacros.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	int major=5;
	int minor=1;
	dev_t dev=makedev(major,minor);
	if(mknod("my_file",S_IFIFO|0766,dev)==-1)
	{
		perror("mknod failed");
		return 1;
	}
	return 0;
}
