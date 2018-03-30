#include <stdlib.h>
#include <stdio.h>
// ab调用ba程序

int main()
{
  int i;
  i = system("ba");
  printf("i = %d\n", i / 0x100);
  return 0;
}
/*
sh: ba: command not found
i = 32512

临时添加环境变量
export PATH=$PATH:程序路径
echo $PATH 查看PATH

运用如下
hello world
i = 0

修改ba程序的return 为100
运用ab程序，通过ab调用ba,输出结果
hello world
i = 25600
若在Win下，会输出100，而在Linux下是25600
原因：POSIX

修改Linux下的源码，上面的i / 0x100
运行结果为100，如下：
hello world
i = 100
*/
