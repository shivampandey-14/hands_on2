
/*
============================================================================
Name : 17c.c
Author : Shivam Pandey
Description :Write a program to execute ls -l | wc.
c. use fcntl
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include<fcntl.h>
int main()
{
        int pipe_id[2];
        pipe(pipe_id);
        int fd=fork();
        if(fd==0)
        {
                close(pipe_id[0]);
		close(STDOUT_FILENO);
                fcntl(pipe_id[1],F_DUPFD,STDOUT_FILENO);
                close(pipe_id[1]);
                execlp("ls", "ls", "-l", NULL);
        }
        else
        {
                wait(NULL);
                close(STDIN_FILENO);
                fcntl(pipe_id[0],F_DUPFD,STDIN_FILENO);
                close(pipe_id[0]);
                execlp("wc","wc",NULL);
        }
        return 0;
}

