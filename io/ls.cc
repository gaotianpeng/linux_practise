
#include "gtest/gtest.h"
extern "C" {
#include "apue.h"
#include <dirent.h>
}

TEST(IO_TEST, ListDir) {
    DIR* dp;
    struct dirent *dirp;
    if ((dp = opendir("/usr/")) == NULL) {
        err_sys("can not open  %s", "/usr");
    }

    while ((dirp = readdir(dp))  != NULL) {
        printf("%s, %d\n", dirp->d_name, dirp->d_type);
    }

    closedir(dp);
}

TEST(IO_TEST, STDIN1) {
#define BUFFSIZE 4096
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("write error");
        }
    }

    if (n < 0) {
        err_sys("read err");
    }
}

TEST(IO_TEST, STDIN2) {
    int c;
    while ((c = getchar()) != EOF) {
        if (putc(c, stdout) == EOF) {
            err_sys("output error");
        }
    }

    if (ferror(stdin)) {
        err_sys("input error");
    }
}

TEST(IO_TEST, PROCESSID) {
    printf("hello world from process ID %ld\n", (long)getpid());
}