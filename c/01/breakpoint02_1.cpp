#include <stdio.h>

/*断点测试2_练习*/

int main(void)
{
	int i;
	char str[6] = "hello";
	char reverse_str[6] = "";

	printf("%s\n", str);
	for (i = 0; i < 5; i++)
		reverse_str[4-i] = str[i];	//reverse_str[5-i]得到\0有字符串的最前即\0olleh
	printf("%s\n", reverse_str);
	return 0;
}

/*
用字符串"hello"初始化一个字符数组str（算上'\0'共6个字符）。
用空字符串""初始化一个同样长的字符数组reverse_str，相当于所有元素用'\0'初始化。
打印str，把str倒序存入reverse_str，再打印reverse_str。
然而结果并不正确：
$ ./main 
hello

本来希望reverse_str打出来是olleh的，结果什么都没有。
重点怀疑对象肯定是循环，那么简单验算一下，
i=0时，reverse_str[5] = str[0]，也就是'h'，
i=1时，reverse_str[4] = str[1]，也就是'e'，
依此类推，i=0,1,2,3,4，共5次循环，正好把h,e,l,l,o五个字母给倒过来了，哪里不对了？
请调试修正这个Bug。
*/
