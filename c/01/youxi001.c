#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//剪刀石头布

int main(void) {
	char gesture[3][10] = { "scissor", "stone", "cloth" };
	int man, computer, result, ret;

	srand(time(NULL));
	while (1) {
		computer = rand() % 3;
	  	printf("\nInput your gesture (0-scissor 1-stone 2-cloth):\n");
		ret = scanf("%d", &man);	//参数1转换说明,参数2读进来的数存到man变量中
	  	if (ret != 1 || man < 0 || man > 2) {
			printf("Invalid input! Please input 0, 1 or 2.\n");
			continue;
		}
		printf("Your gesture: %s\tComputer's gesture: %s\n", gesture[man], gesture[computer]);

		result = (man - computer + 4) % 3 - 1;
		if (result > 0)
			printf("You win!\n");
		else if (result == 0)
			printf("Draw!\n");
		else
			printf("You lose!\n");
	}
	return 0;
}

/*
程序的主体是一个死循环，需要按Ctrl-C退出程序
scanf("%d", &man)，等待用户输入一个整数并回车，这个整数会被scanf函数保存在man这个整型变量里，
如果用户输入合法（输入的确实是整数而不是字符串），则scanf函数返回1，表示成功读入一个数据

思考：(man - computer + 4) % 3 - 1是如何比较出0、1、2这三个数字在“剪刀石头布”意义上的大小的？
*/