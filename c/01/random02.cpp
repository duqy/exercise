#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000		//把整个程序中所有用到N的地方都改为100000了，避免了硬编码（Hard coding）

// 统计每个数字出现的次数

int a[N];

void gen_random(int upper_bound) {
	int i;
	for (i = 0; i < N; i++) {
		a[i] = rand() % upper_bound;
	}
}

int howmany(int value) {
	int count = 0, i;
	for (i = 0; i < N; i++)
		if (a[i] == value)
			++count;
	return count;
}

int main(void) {
	int i;
	gen_random(10);
	printf("value\thow many\n");
	for (i = 0; i < 10; i++)
		printf("%d\t%d\n", i, howmany(i));

	return 0;
}

/*
Win7,64b
输出 
value   how many
0       10072
1       10005
2       9954
3       10132
4       10007
5       10045
6       9869
7       9959
8       9953
9       10004
*/
