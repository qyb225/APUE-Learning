#include "apue.h"

static void sig_usr(int signo);

int main() {
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        err_sys("can't catch SIGUSR1.\n");
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        err_sys("can't catch SIGUSR2.\n");
    }
    while (1) {
        pause();
    }
}

static void sig_usr(int signo) {
    if (signo == SIGUSR1) {
        printf("received SIGUSR1 signal.\n");
    } else if (signo == SIGUSR2) {
        printf("received SIGUSR2 signal.\n");
    }
}