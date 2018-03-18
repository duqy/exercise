#include <iostream>
#include <thread>

using namespace std;

void swap( int a, int b)
{
    int tmp;
    tmp = * a;
    * a = * b;
    * b = tmp;		// * a是什么？
    printf("%s, %s\n", a, b);
}

// int n1, n2;
// swap(n1, n2) ; // n1,n2的值不会被交换






// void my_thread()
// {
// 	puts("hello, world");
// }

int main(int argc, char *argv[])
{
	// std::thread t(my_thread);
	// t.join();

	// system("pause");

	int a = 3;
	int b = 5;
	swap(a, b);
	printf("%s, %s\n", a, b);
	return 0;
}
