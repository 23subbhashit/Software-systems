/*
============================================================================
Name : 15.c
Author : Subbhashit Mukherjee
Description : Write a simple program to send some data from parent to the child process.
Date: 29th Sept 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buff[80];
    int fd[2],p;
    p = pipe(fd);
    if(p == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if (fork()) {
        close(fd[0]); 
        printf("Enter message to the child: ");
        scanf(" %[^\n]", buff); 
        write(fd[1], buff, sizeof(buff));
    }
    else {
        close(fd[1]); 
        read(fd[0], buff, sizeof(buff));
        printf("Message from parent: %s\n", buff);
    }
    wait(0); 
    return 0;
}