#include <iostream>
#include <climits> // 为了使用 INT_MIN 宏

using namespace std;

int main()
{
	int a = 4;
	
	//a += (a++);		//9
	//cout<<a<<endl;
	
	//a += (++a);		//10
	//cout<<a<<endl;
	
	//++a += a;		//10
	//cout<<a<<endl;
	
	//a += a+++a;		//14
	//cout<<a<<endl;
	//Win7_64, tdmgcc11, 			编译结果：9，10，10，14 
	//Win7_64, CFree_mingw3.4.5, 	编译结果：9，10，10，13
	
	cout<<INT_MIN;		//-2147483648
	
	return 0;
}

