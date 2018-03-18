#include <stdio.h>

int main()
{
  int num;  //先声明，后赋值
  num = 100;
  int x = 10;  //声明的同时赋值
  
  int a, b, c;  //同时声明多个变量，然后赋值
  a = 1;
  b = 2;
  c = 3;
  printf("%d\n", num);

  printf("%d\n", 100);  //整形常量
  printf("%f\n", 3.14);  //实型常量
  printf("%c\n", 'A');  //字符常量
  printf("%s\n", "I love mooc!");  //字符串常量
  printf("I love mooc!");
  return 0;
}

/*
100
100
3.140000
A
I love mooc!
I love mooc!
*/

