/*
============================================================================
Name : 20w.c
Author : Subbhashit Mukherjee
Description : 
         Write two programs so that both can communicate by FIFO -Use one way communication.
         This file is for reading through the pipe 
Date: 29th Sept 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *fifopath = "20fifo"; 
    char buff[] = "IIITH>IIITB"; 
    mkfifo(fifopath, 0666);
    int fd = open(fifopath, O_WRONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd, buff, sizeof(buff));
    close(fd);

    return 0;
}
