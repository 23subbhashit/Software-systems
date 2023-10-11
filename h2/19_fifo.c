/*
============================================================================
Name : 19_fifo.c
Author : Subbhashit Mukherjee
Description : 
         Create a FIFO file by
           a. mknod command
           b. mkfifo command
           c. use strace command to find out, which command (mknod or mkfifo) is better.
           d. mknod system call
           e. mkfifo library function
Date: 3rd Octuber 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int result = mkfifo("myfifo", 0666);
    if (result == -1) {
        perror("mkfifo");
        return 1;
    }
    printf("FIFO 'myfifo' created.\n");
    return 0;
}
