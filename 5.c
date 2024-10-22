/*
============================================================================
Name : 5.c
Author : Shivam Pandey
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
    long long int arg_max = sysconf(_SC_ARG_MAX);
    if(arg_max != -1)
    {
        printf("Maximum number of arguments to execute: %lld \n", arg_max);
    }
    long long int child_max = sysconf(_SC_CHILD_MAX);
    if(child_max != -1)
    {
        printf("Maximum number of simultaneous processes: %lld \n", child_max);
    }
    long long int clk_tck = sysconf(_SC_CLK_TCK);
    if(clk_tck != -1)
    {
        printf("Number of clock ticks per second: %lld\n", clk_tck);
    }
    long long int page_size = sysconf(_SC_PAGESIZE);
    if(page_size != -1)
    {
        printf("Page size: %lld bytes\n", page_size);
    }
    long long int open_max = sysconf(_SC_OPEN_MAX);
    if(open_max != -1)
    {
        printf("Maximum number of open files: %lld\n", open_max);
    }
    long long int phys_pages = sysconf(_SC_PHYS_PAGES);
    if(phys_pages != -1)
    {
        printf("Total number of physical pages: %lld\n", phys_pages);
    }
    long long int avail_pages = sysconf(_SC_AVPHYS_PAGES);
    if(avail_pages != -1)
    {
        printf("Number of available physical pages: %lld\n", avail_pages);
    }
    return 0;
}

