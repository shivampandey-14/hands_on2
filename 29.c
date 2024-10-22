/*
============================================================================
Name : 29.c
Author : Shivam Pandey
Description :29. Write a program to remove the message queue.
Date: 21 Sept, 2024.
============================================================================
*/#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
int main()
{
	key_t key = ftok("progfile", 65);
	int msgid = msgget(key, 0666);
	msgctl(msgid, IPC_RMID, NULL);
	printf("Message queue removed successfully.\n");
	return 0;
}
