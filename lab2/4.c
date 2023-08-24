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
