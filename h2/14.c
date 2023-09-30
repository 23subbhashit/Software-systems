#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i, j, fd[2];
    char buf[80];
    i = pipe(fd);
    //printf("i=%d\n", i);
    if(i == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    char messege[] = "Hello\n";
    j = write(fd[1], messege , sizeof(messege)); // j = size of buffer
    //printf("j=%d\n", j);
    read(fd[0], buf, j);
    printf("From pipe: %s\n", buf);
    return 0;
}