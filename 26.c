/*
============================================================================
Name : 26.c
Author : Shivam Pandey
Description :26. Write a program to send messages to the message queue. Check $ipcs -q
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct message_buffer {
	long msg_type;
	char msg_text[100];
};
int main()
{
	key_t key=ftok("progfile",65);
	int msgid=msgget(key,0666|IPC_CREAT);
	struct message_buffer message;
	message.msg_type=1;
	printf("Enter a message: ");
	fgets(message.msg_text,sizeof(message.msg_text),stdin);
	message.msg_text[strcspn(message.msg_text,"\n")]='\0';
	msgsnd(msgid,&message,sizeof(message.msg_text),0);
	printf("Message sent: %s\n", message.msg_text);
	return 0;
}

