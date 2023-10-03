#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    int p = pipe(fd);

    if (p == -1) {
        perror("pipe");
        return 1;
    }

    pid_t ls_pid, wc_pid;

    if ((ls_pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (ls_pid == 0) { 
        close(fd[0]); 

        
        int new_stdout = dup(fd[1]);
        if (new_stdout == -1) {
            perror("dup");
            exit(EXIT_FAILURE);
        }

        close(fd[1]); 
        
        if (new_stdout != STDOUT_FILENO) {
            if (dup2(new_stdout, STDOUT_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(new_stdout); 
        }

        execlp("ls", "ls", "-l", NULL);
        perror("execlp"); 
        exit(EXIT_FAILURE);
    } else { 
        close(fd[1]); 

        if ((wc_pid = fork()) == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (wc_pid == 0) { 
            int new_stdin = dup(fd[0]);
            if (new_stdin == -1) {
                perror("dup");
                exit(EXIT_FAILURE);
            }

            close(fd[0]); 
            if (new_stdin != STDIN_FILENO) {
                if (dup2(new_stdin, STDIN_FILENO) == -1) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
                close(new_stdin); 
            }

            execlp("wc", "wc", NULL);
            perror("execlp"); 
            exit(EXIT_FAILURE);
        } else { 
            close(fd[0]);
            wait(NULL);
            wait(NULL);
        }
    }
    
    return 0;
}
