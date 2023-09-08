/*
============================================================================
Name : 4.c
Author : Subbhashit 
Description : 
        4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.         
Date: 18th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
 int main(void){
     int fd;
     fd = open("program4",O_CREAT|O_EXCL,0644);
     if(fd==-1){
       perror("Error opening a file");
       return 1;
     }
     
     printf("fd=%d",fd);

     close(fd);
     return 0;
 }
