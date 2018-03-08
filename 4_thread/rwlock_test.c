#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_rwlock_t lock;

void *trd_read(void *arg);
void *trd_write(void *arg);

int main() {
    pthread_rwlock_init(&lock, NULL);
    pthread_t tid1, tid2, tid3, tid4;

    pthread_create(&tid1, NULL, trd_read, "tid1");
    pthread_create(&tid2, NULL, trd_read, "tid2");
    pthread_create(&tid3, NULL, trd_write, "tid3");
    pthread_create(&tid4, NULL, trd_read, "tid4");
    pthread_create(&tid3, NULL, trd_write, "tid3");
    pthread_create(&tid4, NULL, trd_read, "tid4");


    pthread_rwlock_destroy(&lock);
    sleep(3);
    exit(0);
}

void *trd_read(void *arg) {
    pthread_rwlock_rdlock(&lock);
    printf("%s READING...\n", (char *)arg);
    sleep(0.5);
    printf("%s END READING\n", (char *)arg);
    pthread_rwlock_unlock(&lock);

    pthread_exit((void *)0);
}

void *trd_write(void *arg) {
    pthread_rwlock_wrlock(&lock);
    printf("%s WRITING...\n", (char *)arg);
    sleep(0.5);
    printf("%s END WRITING\n", (char *)arg);
    pthread_rwlock_unlock(&lock);

    pthread_exit((void *)0);
}