#include <stdio.h>

/*输入字符串转整数*/

int main(void)
{
	int sum = 0, i = 0;
	char input[5];

	while (1) {
		sum = 0;		//虽然sum已经赋了初值0，仍需要在while (1)循环开头加上sum = 0;
		scanf("%s", input);
		for (i = 0; input[i] != '\0'; i++) {
			if (input[i] < '0' || input[i] > '9') {
				printf("Invalid input!\n");
				sum = -1;
				break;
			}
			sum = sum*10 + input[i] - '0';
		}
		printf("input=%d\n", sum);
	}
	return 0;
}

/*
for中添加了if，
如果不是数字就报错退出，不仅输入字母可以报错退出，输入超长的字符串也会报错退出
似乎是两个Bug一起解决掉了，想想为什么输入超长也会报错退出。

治标不治本，因为并没有制止scanf的访问越界

为什么变量i的存储单元紧跟在input数组后面？
为什么同样是访问越界，有时出段错误Segmentation fault有时不出段错误？
为什么访问越界的段错误在函数返回时才出现？
为什么scanf输入整型变量就必须要加&，否则就出段错误，而输入字符串就不要加&？
*/