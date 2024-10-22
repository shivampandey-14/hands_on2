/*
============================================================================
Name : 9.c
Author : Shivam Pandey
Description :Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>

void ignore_signal (int num)
{
	printf("SIGINT ignored! Press Ctrl+C again to exit.\n");
}
int main()
{
	signal(SIGINT,ignore_signal);
	printf("SIGINT is being ignored. Press Ctrl+C to test it.\n");
	sleep(5);
	printf("Resetting SIGINT to default behavior. Press Ctrl+C again to terminate the program.\n");
	signal(SIGINT, SIG_DFL);
	sleep(10);
	printf("Program completed.\n");
	return 0;
}
