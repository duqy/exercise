#include <stdio.h>

int main()
{
  char c = 'a';
  int x;
  double d;
  x = c;			/* 字符类型可以自动转换为整型 */
  d = x;			/* 整型可以自动转换为浮点类型 */
  printf("%d\n", x);
  printf("%f\n", d);

  /* 强制类型转换 */
  double num = 2.5;
  printf("num的整数部分%d\n", (int)num);
  
  return 0;
}

/*
97
97.000000
num的整数部分2
*/
