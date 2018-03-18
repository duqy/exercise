#include <iostream>

// 使用std命名空间
using namespace std;

int main()
{
    // 在屏幕上输出提示信息
    // 在字符串的后面，还输出了一个特殊的操纵符endl
    // endl操纵符的作用是表示一行的结束(end of line),它会让输出换行
    // 并刷新输出缓冲区，让用户可以立即看到输出
    cout<<"请输入两个整数(如：19 83)："<<endl;

    // 用于保存输入数据的变量
    int n1, n2;
    // 从cin提取用户输入的两个整数，输入时，整数之间以空格分隔
    cin>> n1 >> n2;

    // 对数据进行处理
    // 计算两个加数的和，将结果保存到nRes变量
    int nRes = n1 + n2;

    // 将两个加数之和输出到屏幕
    cout<< n1 << " + " << n2 << " = " << nRes <<endl;
    
    return 0;
}