#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000		//把整个程序中所有用到N的地方都改为100000了，避免了硬编码（Hard coding）

// 统计每个数字出现的次数

int a[N];

void gen_random(int upper_bound) {
	int i;
	for (i = 0; i < N; i++)
		srand(time(NULL)); 
		a[i] = rand() % upper_bound;
}

// 统计每个数 都得遍历一遍，效率不高 
int howmany(int value) {
	int count = 0, i;
	for (i = 0; i < N; i++)
		if (a[i] == value)
			++count;
	return count;
}

int main(void) {
	int i, j, histogram[10] = {};	//histogram的所有元素初始化为0
	gen_random(10);
	for (i = 0; i < N; i++)
		// 每次循环中，a[i]就是随机数，而这个随机数同时也是histogram的下标，这个随机数每出现一次就把histogram中相应元素加1
		++histogram[a[i]];		//只需一遍，就可统计所有数字的各个总数 
	for(j = 0; j < 10; j++)
		printf("%d\t%d\n", j, histogram[j]);

	return 0;
}

/*
Win7,64b
输出 
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
从统计结果看，每次统计的结果都是一样的， 
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
不仅如此，在别的计算机上运行该程序产生的随机数很可能也是这样的。
这正说明了这些数是伪随机数，是用一套确定的公式基于某个初值算出来的，只要初值相同，随后的整个数列就都相同
实际应用中不可能使用每次都一样的随机数。
因此，C标准库允许我们自己指定一个初值，然后在此基础上生成伪随机数，这个初值称为Seed，可以用srand(Seed)指定Seed。
通常通过别的途径得到一个不确定的数作为Seed，例如调用time函数得到当前系统时间
距1970年1月1日00:00:00[17]的秒钟数，然后传给srand：
srand(time(NULL));
然后再调用rand，得到的随机数就和刚才完全不同了。调用time函数需要包含头文件time.h，这里的NULL表示空指针。


srand(time(NULL)); 加入后，统计好像不对
0       100000
1       0
2       0
3       0
4       0
5       0
6       0
7       0
8       0
9       0


 
*/
