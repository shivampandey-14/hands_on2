/*
============================================================================
Name : 2.c
Author : Shivam Pandey
Description : 2. Write a program to print the system resource limits. Use getrlimit system call.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
void print_limit(int resources,char *name)
{
	struct rlimit r;
	if(getrlimit(resources,&r)==0)
	{
		printf("%s\n",name);
	
		printf("Soft limit: %ld\n",(long)r.rlim_cur);
		printf("Hard limit: %ld\n",(long)r.rlim_max);
	}
	else
	{
		perror("getrlimit");
		exit(EXIT_FAILURE);
	}
}
int main()
{
	print_limit(RLIMIT_CPU,"CPU LIMIT");
	print_limit(RLIMIT_FSIZE,"File Size");
	print_limit(RLIMIT_DATA, "Data Segment Size");
    	print_limit(RLIMIT_STACK, "Stack Size");
    	print_limit(RLIMIT_CORE, "Core File Size");
    	print_limit(RLIMIT_RSS, "Resident Set Size");
    	print_limit(RLIMIT_NPROC, "Number of Processes");
	return 0;
}
