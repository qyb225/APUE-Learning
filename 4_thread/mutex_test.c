#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
void *fn_trd(void *arg);

int main() {
    int share_var = 0;
    pthread_t tid1, tid2, tid3;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid1, NULL, fn_trd, (void *)&share_var);
    pthread_create(&tid2, NULL, fn_trd, (void *)&share_var);
    pthread_create(&tid3, NULL, fn_trd, (void *)&share_var);

    sleep(1);
    pthread_mutex_destroy(&mutex);
    exit(0);
}

void *fn_trd(void *arg) {
    int *share_var_ptr = (int *)arg;
    
    pthread_mutex_lock(&mutex);
    int i;
    for (i = 0; i < 100000; ++i) {
        ++(*share_var_ptr);
    }
    pthread_mutex_unlock(&mutex);

    printf("share_var: %d\n", *share_var_ptr);
    pthread_exit((void *)0);
}