/*
============================================================================
Name : 24.c
Author : Subbhashit 
Description : 
        24. Write a program to create an orphan process.           
Date: 18th Aug, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
   if(!fork()){
     printf("I'm child process, my parent_id before it left me:%d\n",getppid());
     sleep(1);
     printf("I'm child process, my current grandparent is:%d",getppid());
   }
   else{
     printf("This is parent process:%d\n",getpid());
     exit(0);
   }
}
