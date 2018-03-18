#include <stdio.h>

#define PI 3.14			/* 定义一圆周率常量 */

int main()
{
  //PI = 3.15;  // 常量不可改变
  printf("圆周率：%f\n", PI);
  return 0;
}
/*
  PI = 3.15;
muke003.c:7:6: error: lvalue required as left operand of assignment
   PI = 3.15;
      ^
// PI = 3.15;
圆周率：3.140000
*/
