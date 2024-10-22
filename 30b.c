/*
--------------------------------------------------------
--------------------------------------------------------

Name - 30a.c
Author : Shivam Pandey
Description - Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
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
    key_t key=ftok("shmfile", 65);
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
    char *data=(char*)shmat(shmid,NULL,SHM_RDONLY);
    if(data==(char*)-1) 
    {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }
    printf("Trying to write to shared memory in read-only mode...\n");
    strcpy(data, "Attempt to overwrite in read-only mode");
    if(shmdt(data)==-1)
    {
        perror("shmdt failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}

