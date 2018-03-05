#include <stdlib.h>
#include <stdio.h>

static void exit1();
static void exit2();

int main() {
    if (atexit(exit2) != 0) {
        printf("can't register exit2\n");
    }
    if (atexit(exit1) != 0) {
        printf("can't register exit1\n");
    }
    if (atexit(exit1) != 0) {
        printf("can't register exit1\n");
    }

    printf("main is done\n");
    return 0;
}

static void exit1() {
    printf("exit1 handler\n");
}

static void exit2() {
    printf("exit2 handler\n");
}