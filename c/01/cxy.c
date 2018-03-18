#include "stdio.h"

int main(int argc, char *argv[])
{
  int x = 0;
  printf("%p\n", &x); /* 0x7ffcff21cf24 */

  int* px, not_a_pointer;  // px是一个指向int型的指针
  px = &x;  //把x的地址保存到px中
  printf("%p\n", (void *)px); /* 0x7ffcdaf304dc */
  printf("%zu, %zu\n", sizeof(px), sizeof(not_a_pointer)); /* 在64位，8，4 */
  
  
  return 0;
}
