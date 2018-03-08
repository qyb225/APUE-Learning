#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *thr_fn(void *arg);
void print_tid(const char *s);

int main() {
    pthread_t tid;
    int err;

    err = pthread_create(&tid, NULL, thr_fn, NULL);

    if (err != 0) {
        printf("can't create new thread!\n");
        exit(0);
    }
    
    print_tid("main thread");

    sleep(1);
    exit(0);
}

void print_tid(const char *s) {
    pthread_t tid = pthread_self();
    printf("%s tid: %lu (0x%lx)\n", s, (long)tid, (long)tid);
}

void *thr_fn(void *arg) {
    printf("new thread created!\n");
    print_tid("new thread");

    pthread_exit((void *)0);
}