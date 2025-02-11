

/*
============================================================================
Name : 3.c
Author : Shivam Pandey
Description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
int main()
{
	struct rlimit r;
	printf("Heloo\n");
	if(getrlimit(RLIMIT_NOFILE,&r)==0)
	{
		printf("Soft limit: %ld\n",(long)r.rlim_cur);
		printf("Hard limit: %ld\n",(long)r.rlim_max);
	}
	else 
	{
        	perror("getrlimit failed");
        	exit(EXIT_FAILURE);
	}
	r.rlim_cur=2048;

	if(setrlimit(RLIMIT_NOFILE, &r) != 0)
       	{
        	perror("setrlimit failed");
        	exit(EXIT_FAILURE);
    	}
       	else 
	{
        	printf("Soft limit successfully set to 2048.\n");
    	}
	if(getrlimit(RLIMIT_NOFILE,&r)==0)
        {
                printf("Soft limit: %ld\n",(long)r.rlim_cur);
                printf("Hard limit: %ld\n",(long)r.rlim_max);
        }
        else
        {
                perror("getrlimit failed");
                exit(EXIT_FAILURE);
        }
	return 0;
}
