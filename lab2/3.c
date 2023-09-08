/*
============================================================================
Name : 3.c
Author : Subbhashit 
Description : 
        3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call      
Date: 18th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Path to the file to be created
    const char* filename = "my_file.txt";

    // Create the file using creat() system call
    int fd = creat(filename, 0644);  // 0644 represents file permissions

    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    printf("File created successfully with file descriptor: %d\n", fd);

    // Close the file descriptor
    close(fd);

    return 0;
}
