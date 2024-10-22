/*
============================================================================
Name : 19d.c
Author : Shivam Pandey
Description :Create a FIFO file by
d. mkfifo library function
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	char *fifo_path="file_by_fifo";
	if (mkfifo(fifo_path, 0666) == -1)
	{
		perror("error occured");
		return 1;
	}
	return 0;
}
