#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    //execl
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);
    
    
    // xeclp
    printf("Using execlp:\n");
    execlp("ls", "ls", "-Rl", NULL);
    
    
    //execle
    printf("Using execle:\n");
    char *envp[] = {NULL}; 
    execle("/bin/ls", "ls", "-Rl", NULL, envp);
    
    
    //execv
    printf("Using execv:\n");
    //char *args[] = {"/bin/ls", "ls", "-Rl", NULL};
    //execv("/bin/ls", args);
    
    
    //execvp
    printf("Using execvp:\n");
    //char *args[] = {"/bin/ls", "ls", "-Rl", NULL};
    //execvp("ls", args);
    
    
    return 0;
} 
