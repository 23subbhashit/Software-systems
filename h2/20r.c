/*
============================================================================
Name : 20r.c
Author : Subbhashit Mukherjee
Description : 
         Write two programs so that both can communicate by FIFO -Use one way communication.
         This file is for writing through the pipe 
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
    char buff[256]; 
    mkfifo(fifopath, 0666);
    int fd = open(fifopath, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    int bytesRead = read(fd, buff, sizeof(buff));
    if (bytesRead == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Received message: %s\n", buff);
    close(fd);

    return 0;
}
