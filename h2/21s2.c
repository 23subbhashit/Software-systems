#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd1, fd2;
    char buff1[100];
    char buff2[100];

    fd1 = open("myfifo1", O_WRONLY);
    if (fd1 == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    fd2 = open("myfifo2", O_RDONLY);
    if (fd2 == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    while (1) {
        printf("Sender/Receiver 2: Enter a message (or 'exit' to quit): ");
        scanf(" %[^\n]", buff1);
        write(fd1, buff1, sizeof(buff1));

        if (strcmp(buff1, "exit") == 0)
            break;

        read(fd2, buff2, sizeof(buff2));

        printf("Sender/Receiver 2: Received response: %s\n", buff2);
    }

    close(fd1);
    close(fd2);

    return 0;
}
