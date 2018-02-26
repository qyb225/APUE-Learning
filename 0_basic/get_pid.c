#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);
    exit(0);
}