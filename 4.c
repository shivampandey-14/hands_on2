/*
============================================================================
Name : 4.c
Author : Shivam Pandey
Description : Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter.
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

static inline int rdtsc(void){
	int lo,hi;
	__asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
	return ((long long)hi<<32) | lo;
}
int main()
{
	int start,end;
	start=rdtsc();
	for(int i=0;i<100;i++)
		getppid();
	end=rdtsc();
	int x=end-start;
	x=x/4.6;
	printf("Time taken to execute 100 ppid calls: %d clock cycles\n" ,x);
	return 0;
}
