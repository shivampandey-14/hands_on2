/*
============================================================================
Name : 24.c
Author : Shivam Pandey
Description :24. Write a program to create a message queue and print the key and message queue id.
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>

#include<stdlib.h>
#include<sys/ipc.h>
int main()
{
	key_t key=ftok("/home/shivam/ss_lab/lab2",'A');
	if(key==-1) 
	{
        	perror("ftok");
        	return 1;
    	}
	printf("Generate key is: %d\n",key);
	return 0;
}
