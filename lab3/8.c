/*
============================================================================
Name : 8.c
Author : Subbhashit 
Description : 
        8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
        Close the file when end of file is reached.           
Date: 17th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char* argv[]) {
    int fd;
    char filename[100];
    char buffer[1]; // Read one character at a time
    ssize_t bytesRead;
    if (argc!=2){
        printf("You are useless");
        return 0;
    }

    // Open the file in read-only mode
    fd = open(argv[1],O_RDONLY); 
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read and display each line from the file
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        if (buffer[0] == '\n') {
            write(STDOUT_FILENO, "\n", 1);
        } else {
            write(STDOUT_FILENO, buffer, 1);
        }
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    return 0;
}
