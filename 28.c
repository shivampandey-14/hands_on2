/*
============================================================================
Name : 28.c
Author : Shivam Pandey
Description :28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	key_t key=ftok("progfile",65);
	int msgid=msgget(key,0777|IPC_CREAT);
	struct msqid_ds msgq_ds;
	msgctl(msgid,IPC_STAT,&msgq_ds);
	printf("Current permissions: %o\n",msgq_ds.msg_perm.mode &0777);
	msgq_ds.msg_perm.mode=(msgq_ds.msg_perm.mode & ~ 0777) |0660;
	printf("New permissions: %o\n", msgq_ds.msg_perm.mode & 0777);
	return 0;
}
