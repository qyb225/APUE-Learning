#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        printf("hello\n");
        printf("world");
        _exit(0);
    } else if (pid > 0) {
        sleep(2);
        printf("hello\n");
        printf("world");
        exit(0);
    }
}