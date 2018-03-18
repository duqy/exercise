#include <stdio.h>

/*断点测试2*/

int main(void)
{
	int sum = 0, i = 0;
	char input[5];

	while (1) {
		scanf("%s", input);
		for (i = 0; input[i] != '\0'; i++)
			sum = sum*10 + input[i] - '0';
		printf("input=%d\n", sum);
	}
	return 0;
}

/*
原因在于新的循环没有把sum归零
虽然sum已经赋了初值0，仍需要在while (1)循环开头加上sum = 0;
*/