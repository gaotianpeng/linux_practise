#include "gtest/gtest.h"

extern "C" {
#include "apue.h"
#include <dirent.h>
#include <sys/wait.h>
}

TEST(SHELL_TEST, SHELL1) {
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) -1] == '\n') {
            buf[strlen(buf) - 1] = 0; // replace newline with null
        }

        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {
            execlp(buf, buf, (char*)0);
            err_ret("could not execute: %s", buf);
            exit(127);
        }

        // parent
        if ((pid == waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }
        printf("%%");
    }

    exit(0);
}


