#include "apue.h"
#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    DIR *dptr;
    struct dirent *dirptr;
    if (argc != 2) {
        err_quit("usage: ls directory_name\n");
    }

    dptr = opendir(argv[1]);
    if (!dptr) {
        err_sys("can't open %s", argv[1]);
    }
    while ((dirptr = readdir(dptr))) {
        printf("%s\n", dirptr->d_name);
    }
    closedir(dptr);
    exit(0);
}