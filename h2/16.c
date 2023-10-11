/*
============================================================================
Name : 16.c
Author : Subbhashit Mukherjee
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 29th Sept 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buff1[80],buff2[80];
    int fd1[2],p1,fd2[2],p2;
    p1= pipe(fd1);
    if(p1 == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }
    p2= pipe(fd2);
    if(p2 == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }
    if (fork()) {
        close(fd1[1]); // Close write-end of child
        close(fd2[0]); // Close read-end of parent
        read(fd1[0], buff1, sizeof(buff1));
        printf("Message from child: %s\n", buff1);
        printf("Enter message to child: ");
        scanf(" %[^\n]", buff2);
        write(fd2[1], buff1, sizeof(buff1));
    }
    else {
        close(fd1[0]); // Close read-end of child
        close(fd2[1]); // Close write-end of parent
        printf("Enter message to parent: ");
        scanf(" %[^\n]", buff1);
        write(fd1[1], buff1, sizeof(buff1));
        read(fd2[0], buff2, sizeof(buff2));
        printf("Message from parent: %s\n", buff2);

    }
    
    wait(0); 
    return 0;
}