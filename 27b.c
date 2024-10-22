/*
============================================================================
Name : 27b.c
Author : Shivam Pandey
Description :Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag
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
	char msg_text[100];
};
int main()
{
	key_t key=ftok("procfile",65);
	int msgid=msgget(key,0666|IPC_CREAT);
	struct message_buffer buff;
	msgrcv(key,&buff,sizeof(buff.msg_text),0,IPC_NOWAIT);
	printf("message recived is %s\n",buff.msg_text);
	return 0;
}
