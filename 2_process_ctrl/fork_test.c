#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int globvar = 10;

int main() {
    int var = 100;
    pid_t pid;

    printf("before fork buffer ");
    pid = fork();
    if (pid == 0) {
        //子进程修改变量
        ++globvar;
        ++var;
    } else if (pid > 0) {
        //父进程 sleep 保证子进程先输出
        sleep(2);
    }
    printf("pid = %d, globvar = %d, var = %d\n",
           getpid(), globvar, var);
    exit(0);
}