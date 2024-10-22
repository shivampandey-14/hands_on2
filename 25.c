/*
============================================================================
Name : 25.c
Author : Shivam Pandey
Description :25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	key_t key=ftok("Progfile",65);
	int msgid=msgget(key,0666|IPC_CREAT);
	struct msqid_ds buf;
	if(msgctl(msgid,IPC_STAT,&buf)==-1)
	{
		perror("msgctl");
	        exit(EXIT_FAILURE);
	}
        printf("Access permissions: %o\n", buf.msg_perm.mode);

	printf("UID: %d\n", buf.msg_perm.uid);
	printf("GID: %d\n", buf.msg_perm.gid);
	printf("Time of last message sent: %s", ctime(&buf.msg_stime));
	printf("Time of last message received: %s", ctime(&buf.msg_rtime));
	printf("Time of last change in the message queue: %s", ctime(&buf.msg_ctime));
	printf("Current number of bytes in the queue: %lu\n", buf.__msg_cbytes);
	printf("Number of messages in the queue: %lu\n", buf.msg_qnum);
	printf("Maximum number of bytes allowed in the queue: %lu\n", buf.msg_qbytes);

	printf("PID of the last msgsnd: %d\n", buf.msg_lspid);
        printf("PID of the last msgrcv: %d\n", buf.msg_lrpid);
	return 0;
}

