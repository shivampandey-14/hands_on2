
/*
============================================================================
Name : 7.c
Author : Shivam Pandey
Description :Write a simple program to print the created thread ids.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void* thread_function(void* arg) {
    printf("Thread %d ID: %lu\n", *((int*)arg), pthread_self());
    return NULL;
}
int main() {
    pthread_t threads[3];
    int thread_ids[3];
    int i;
    for(i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        if(pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }
    for(i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished executing.\n");

    return 0;
}

