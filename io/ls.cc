
#include "gtest/gtest.h"

extern "C" {
#include "apue.h"
#include <dirent.h>
}

TEST(SortTest, BiggerThanTwiceTest) {
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