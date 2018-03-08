#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct foo {
    int a, b, c, d;
};

void *ptr_fn(void *arg);
void *ptr_fn_2(void *arg);
void printfoo(const struct foo *fp);


int main() {
    pthread_t tid;
    pthread_t tid2;
    struct foo *fp;

    int *args = malloc(sizeof(int) * 4);
    args[0] = 100;
    args[1] = 200;
    args[2] = 300;
    args[3] = 400;

    int err = pthread_create(&tid, NULL, ptr_fn, args);
    if (err != 0) {
        printf("can't create new thread\n");
        exit(0);
    }

    err = pthread_create(&tid2, NULL, ptr_fn_2, NULL);
    if (err != 0) {
        printf("can't create new thread1\n");
        exit(0);
    }

    pthread_join(tid, (void **)&fp);
    printfoo(fp);

    free(fp);
    free(args);
    
    sleep(0.5);
    exit(0);
}

void printfoo(const struct foo *fp) {
    printf("%d, ", fp->a);
    printf("%d, ", fp->b);
    printf("%d, ", fp->c);
    printf("%d\n", fp->d);
}

void *ptr_fn_2(void *arg) {
    pthread_exit((void *)0);
}

void *ptr_fn(void *arg) {
    int *args = (int *)arg;
    int a = args[0], b = args[1], 
        c = args[2], d = args[3];
    struct foo *fp = malloc(sizeof(struct foo));
    fp->a = a;
    fp->b = b;
    fp->c = c;
    fp->d = d;
    pthread_exit((void *)fp);
}