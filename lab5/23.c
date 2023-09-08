//cat /proc/process_id/stat

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

   if(!fork()){
      printf("Child process %d is executing....\n",getpid());   
   }else{
      printf("Parent process %d is executing..\n",getpid());
      sleep(30);
      wait(0);
   }
   return 1;
}
