#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("hello world\n");
  return 0;
}


/*
<头文件>，代表让C语言编译器去系统目录下寻找相关的头文件;/usr/include/
“头文件”，代表让C语言编译器去用户当前目录下寻找相关头文件

源文件-->预编译-->编译-->链接+C库-->可执行程序

gcc
-E  预编译；预编译是将include包含的头文件内容替换到C文件中中，同时将代码中没用的注释部分删除
    /usr/include/stdio.h
-S汇编
-c编译,将代码编译为二进制的机器指令
链接
Gcc没有任何参数，代表就是链接


~/work/code/c/01 $ gcc -E gc.cpp -o gc.i
~/work/code/c/01 $ gcc -S gc.i -o gc.s
错误：
In file included from gc.cpp:1:0:
/usr/include/stdio.h:29:8: error: expected identifier or ‘(’ before string constant
 __BEGIN_DECLS
        ^~~
gc.cpp: In function ‘main’:
gc.cpp:5:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("hello world\n");
   ^~~~~~
gc.cpp:5:3: warning: incompatible implicit declaration of built-in function ‘printf’
gc.cpp:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’

原因：#include <stdio.h>
但是此文件有#include <stdio.h>
不知为什么报错

换成g++可通过
~/work/code/c/01 $ g++ -E gc.cpp -o gc.i
~/work/code/c/01 $ g++ -S gc.i -o gc.s

gcc -c gc.s -o gc.o  编译成机器码

file gc.o   查看文件类型
gc.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped

gcc -o gc gc.o  //gc.o与C库链接成可执行文件gc
./gc 即可运行

man gcc  帮助
*/
