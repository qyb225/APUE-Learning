#include "apue.h"
#include <sys/wait.h>

/*signal-catching function*/
static void sig_int(int);

int main() {
    char buf[1024];
    pid_t pid;
    int status; /*子进程结束状态*/
    
    if (signal(SIGINT, sig_int) == SIG_ERR) {
        err_sys("signal error\n");
    }

    printf("%% ");
    while (fgets(buf, 1024, stdin)) {
        int len = strlen(buf);
        if (buf[len - 1] == '\n') {
            /*execlp 要求 null 结尾而不是 \n*/
            buf[len - 1] = 0;
        }
        pid = fork();
        if (pid < 0) {
            err_sys("fork error\n");
        } else if (pid == 0) {
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }
        /*父进程等待子进程结束后返回*/
        waitpid(pid, &status, 0);
        printf("%% ");
    }
    exit(0);
}

void sig_int(int signo) {
    printf(" interrupt\n");
}