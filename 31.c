/*
--------------------------------------------------------
--------------------------------------------------------

Name - 31.c
Author : Shivam Pandey
Description - Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
 Date: 23/09/2024


--------------------------------------------------------
--------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	sem_t *b_sem;
	sem_t *c_sem;	
	b__sem=sem_open("/binary_sem", O_CREAT,S_IRUSR|S_IWUSR,1);
	if (b_sem == SEM_FAILED) 
	{
        	perror("sem_open for binary semaphore");
       		return 1;
	}
	c_sem=sem_open("/counting_sem", O_CREAT,S_IRUSR|S_IWUSR,1);
	if (c_sem == SEM_FAILED) 
	{
	        perror("sem_open for counting semaphore");
	        return 1;
	}
	printf("Semaphores created and initialized successfully...\n");
	return 0;
}
