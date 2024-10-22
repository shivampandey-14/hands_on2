/*
--------------------------------------------------------
--------------------------------------------------------

Name - 30a.c
Author : Shivam Pandey
Description - Write a program to create a shared memory.
d. remove the shared memory
 Date: 23/09/2024


--------------------------------------------------------
--------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#define SHM_SIZE 1024

int main() 
{
    key_t key = ftok("shmfile", 65);
    if(key==-1) 
    {
        perror("ftok failed");
        exit(1);
    }
    int shmid=shmget(key,SHM_SIZE,0666|IPC_CREAT);
    if(shmid==-1)
    {
        perror("shmget failed");
        exit(1);
    }
    char *str = (char *)shmat(shmid, NULL, 0);
    if(str==(char *)(-1)) 
    {
        perror("shmat failed");
        exit(1);
    }
    strcpy(str, "Hello, Shared Memory!");
    printf("Written to shared memory: %s\n", str);
    if(shmdt(str)==-1) 
    {
        perror("shmdt failed");
        exit(1);
    }
    if(shmctl(shmid,IPC_RMID,NULL)==-1) 
    {
        perror("shmctl failed");
        exit(1);
    }
    printf("Shared memory removed.\n");
    return 0;
}

