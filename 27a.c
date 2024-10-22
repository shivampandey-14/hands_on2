/*
============================================================================
Name : 27a.c
Author : Shivam Pandey
Description :Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct message_buffer{
	long msg_type;
	char text_msg[100];
};
int main()
{
	key_t key=ftok("progfile",65);
	int msgid=msgget(key,0666|IPC_CREAT);
	struct message_buffer buff;
	msgrcv(key,&buff,sizeof(buff.text_msg),0,0);
	printf("Message received: %s\n", buff.text_msg);
	return 0;
}
