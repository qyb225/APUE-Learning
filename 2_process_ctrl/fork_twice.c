#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    pid = fork();
    if (pid == 0) {
        pid = fork();
        if (pid > 0) {
            //父亲生下儿子直接退出，儿子会被收养
            exit(0);
        }
        sleep(0.5);
        printf("I'm son after second fork. ");
        printf("my parent's pid: %d\n", getppid());
        exit(0);
    }
    //爷爷生下父亲后直接等待为其收尸
    waitpid(pid, NULL, 0);

    //爷爷尽情快活

    exit(0);
}