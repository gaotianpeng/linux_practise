
#include "gtest/gtest.h"
extern "C" {
#include "apue.h"
}
#include <dirent.h>

using namespace std;

TEST(SortTest, BiggerThanTwiceTest) {
	DIR *dp;
    struct dirent *dirp;
    if ((dp = opendir("./")) == NULL)
        err_sys("can't open %s", "./");

    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);
    closedir(dp);
}