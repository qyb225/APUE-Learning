#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    pid = fork();
    if (pid == 0) {
        sleep(0.5);
        printf("child exit\n");
        _exit(0);
    }
    while (waitpid(pid, NULL, WNOHANG) == 0) {
        printf("My child doesn't exit.\n");
    }
    printf("My child exit!\n");
    exit(0);
}