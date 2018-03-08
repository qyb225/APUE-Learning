#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        execl("./add.out", "add.out", "8", "3", (char *)0);
        _exit(0);
    }
    waitpid(pid, NULL, 0);
    exit(0);
}