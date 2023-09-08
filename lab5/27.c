/*
============================================================================
Name : 27.c
Author : Subbhashit 
Description : 
        27. Write a program to execute ls -Rl by the following system calls
            a. execl
            b. execlp
            c. execle
            d. execv
            e. execvp           
Date: 6th Sept,, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // execl
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);

    // execlp
    printf("Using execlp:\n");
    execlp("ls", "ls", "-Rl", NULL);

    // execle
    printf("Using execle:\n");
    char *envp[] = { NULL };
    execle("/bin/ls", "ls", "-Rl", NULL, envp);

    // execv
    printf("Using execv:\n");
    char *args[] = { "/bin/ls", "-Rl", NULL };
    execv("/bin/ls", args);

    // execvp
    printf("Using execvp:\n");
    execvp("ls", args);

    return 0;
}
