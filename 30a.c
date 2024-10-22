/*
--------------------------------------------------------
--------------------------------------------------------

Name - 30a.c
Author : Shivam Pandey
Description - Write a program to create a shared memory.
a. write some data to the shared memory
 Date: 23/09/2024


--------------------------------------------------------
--------------------------------------------------------
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    key_t key=ftok("shmfile", 'A');
    if(key==-1)
    {
        perror("ftok failed");
        exit(EXIT_FAILURE);
    }
    int shmid=shmget(key, 1024, 0666 | IPC_CREAT);
    if(shmid==-1) 
    {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }
    char *data=(char*)shmat(shmid, NULL, 0);
    if(data==(char*)-1) 
    {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }
    printf("Writing to shared memory: 'Hello, Shared Memory!'\n");
    strcpy(data, "Hello, Shared Memory!");
    if(shmdt(data)==-1)
    {
        perror("shmdt failed");
        exit(EXIT_FAILURE);
    }
    printf("Data written to shared memory.\n");
    return 0;
}

