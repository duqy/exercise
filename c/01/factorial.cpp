int factorial(int n) {
	int result = 1;		//累加器（Accumulator）, 初值为1
	while (n > 0) {
		result = result * n;
		n = n - 1;		//n是循环变量（Loop Variable）
	}
	return result;
}


int factorial(int n) {
	int result = 1;
	int i = 1;
	do {
		result = result * i;
		i = i + 1;
	} while (i <= n);		//注意while(控制表达式)后面一定要加;号

	return result;
}


int factorial(int n) {
	int result = 1;
	int i;
	for(i = 1; i <= n; ++i)		// ++前缀自增运算符（Prefix Increment Operator）
		result = result * i;
	return result;
}

int factorial(int n) {
	int result = 1;
	for(int i = 1; i <= n; i++)
		result = result * i;
	return result;
}
//C99引入一种新的for循环，规定控制表达式1的位置可以有变量定义