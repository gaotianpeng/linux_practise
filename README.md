# 下载源码
``` bash
# 构建步骤
git clone --recurse-submodules git@github.com:gaotianpeng/linux_practise.git

cd cpp_algo
mkdir build && cd build
cmake ..

./linux_practise

# 检查内存泄漏(Linux)
valgrind --tool=memcheck --leak-check=full  ./linux_practise
```