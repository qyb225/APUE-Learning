#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void quick_sort(int *nums, int lo, int hi);
void swap(int *nums, int i, int j);
void print_nums(int *nums, int lo, int hi);
void merge(int *nums, int lo, int mi, int hi);

void *trd_sort(void *arg);

int nums_array[] = { 8, 4, 9, 0, 4, 1, 0, 8, 2, 8, 4, 9, 0, 4, 1, 0, 8, 2 };

pthread_barrier_t br;

int main() {
    pthread_barrier_init(&br, NULL, 3);
    pthread_t tid1, tid2;
    int split_array[] = { 0, 9, 18 };

    pthread_create(&tid1, NULL, trd_sort, (void *)(split_array));
    pthread_create(&tid2, NULL, trd_sort, (void *)(split_array + 1));
    pthread_barrier_wait(&br);

    merge(nums_array, 0, 9, 18);

    pthread_barrier_destroy(&br);

    print_nums(nums_array, 0, 18);
    exit(0);
}

void quick_sort(int *nums, int lo, int hi) {
    if (hi - lo < 2) {
        return;
    }
    int piv = lo;
    int pivot = nums[piv];
    int i = lo + 1;
    while (i < hi) {
        if (nums[i] <= pivot) {
            swap(nums, ++piv, i);
        }
        ++i;
    }
    swap(nums, lo, piv);
    quick_sort(nums, lo, piv);
    quick_sort(nums, piv + 1, hi);
}

void swap(int *nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void print_nums(int *nums, int lo, int hi) {
    while (lo < hi) {
        printf("%d ", nums[lo]);
        ++lo;
    }
    printf("\n");
}

void *trd_sort(void *arg) {
    int *args = (int *)arg;
    int lo = args[0];
    int hi = args[1];

    quick_sort(nums_array, lo, hi);
    pthread_barrier_wait(&br);

    pthread_exit((void *)0);
}

void merge(int *nums, int lo, int mi, int hi) {
    int *order = malloc(sizeof(int) * (hi - lo));
    int count = 0;
    int i = lo, j = mi;
    while (i < mi && j < hi) {
        if (nums[i] < nums[j]) {
            order[count++] = nums[i++];
        } else {
            order[count++] = nums[j++];
        }
    }
    while (i < mi) {
        order[count++] = nums[i++];
    }
    while (j < hi) {
        order[count++] = nums[j++];
    }
    count = 0;
    while (lo < hi) {
        nums[lo++] = order[count++];
    }
    free(order);
}