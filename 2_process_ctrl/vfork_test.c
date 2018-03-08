#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int globvar = 10;

int main() {
    int var = 100;
    pid_t pid;

    printf("before vfork\n");
    pid = vfork();

    if (pid == 0) {
        //Child
        ++globvar;
        ++var;
        _exit(0);
    }
    //Parent
    printf("pid = %d, globvar = %d, var = %d\n", 
           pid, globvar, var);
    exit(0);
}