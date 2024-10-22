/*
============================================================================
Name : 32.c
Author : Shivam Pandey
Enrollment Number : MT2024145
Description :Write a program to implement semaphore to protect any critical section.
            a. rewrite the ticket number creation program using semaphore
            b. protect shared memory from concurrent write access
            c. protect multiple pseudo resources ( may be two) using counting semaphore
            d. remove the created semaphore

output : 

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <string.h>

#define SHM_SIZE 1024  
#define TRAIN_COUNT 2 

struct ticket_db {
    int ticket_count[TRAIN_COUNT]; 
};

int main() {
    sem_t *sem_train[TRAIN_COUNT];
    int input, shmid;
    struct ticket_db *db;

    for (int i = 0; i < TRAIN_COUNT; i++) {
        char sem_name[16];
        sprintf(sem_name, "/train_sem_%d", i + 1);
        sem_train[i] = sem_open(sem_name, O_CREAT, 0644, 1); 
    }

    key_t key = ftok("shmfile", 65); 
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    db = (struct ticket_db *)shmat(shmid, NULL, 0);

    if (db->ticket_count[0] == 0 && db->ticket_count[1] == 0) {
        for (int i = 0; i < TRAIN_COUNT; i++) {
            db->ticket_count[i] = 1;  
        }
    }

    printf("Select Train number (1 or 2): \n");
    scanf("%d", &input);
    if (input < 1 || input > TRAIN_COUNT) {
        printf("Invalid train number.\n");
        return 1;
    }

    int train_index = input - 1; 
    printf("Waiting for other user to complete booking for train %d\n", input);
    sem_wait(sem_train[train_index]);

    printf("Current Ticket Number for Train %d: %d\n", input, db->ticket_count[train_index]);
    db->ticket_count[train_index]++;

    printf("To Book Ticket, Press Enter... \n");
    getchar(); 
    getchar();

    printf("Booked.\n");
    printf("Your Ticket Number for Train %d is: %d\n", input, db->ticket_count[train_index]);
    sem_post(sem_train[train_index]);

    if (shmdt(db) == -1) {
        perror("Error detaching shared memory");
        exit(1);
    }


    /*
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Error removing shared memory");
        exit(1);
    }

    for (int i = 0; i < TRAIN_COUNT; i++) {
        char sem_name[16];
        sprintf(sem_name, "/train_sem_%d", i + 1);
        sem_unlink(sem_name);
    }

    printf("Shared memory and semaphores removed.\n");
    */

    return 0;
}
