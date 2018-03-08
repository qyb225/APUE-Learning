#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        sleep(2);
        printf("%d\n", getppid());
        exit(0);
    } else {
        exit(0);
    }
}