#include <iostream>
#include <cstring>  //引入字符查找函数strchr()所在的头文件

using namespace std;

int CountChar(const char* str, const char c)
{
    // 从str的开始位置查找字符C
    char* pos = strchr(str, c);

    // 如果strchr()返回值为nullptr,则意味着
    // 在字符串中再也找不到目标字符，递归的终止条件得到满足
    // 则结束函数的递归调用，直接返回本次的查找结果0
    if(nullptr == pos)
    {
        return 0;
    }
    // 如果没有到达终止条件，则将本次查找结果1统计在内，
    // 并在新的开始位置pos+1开始下一次查找，实现函数的递归调用
    return 1 + CountChar(pos + 1, c);
}

int int main()
{
    char str[] = "Thought is a seed";
    char c = 'h';  // 目标字符串
    int nCount = CountChar(str, c);

    cout<<"字符\'"<<c<<"\'在\""<<str<<"\"中出现了"<<nCount<<"次"<<endl;
    
    return 0;
}

// 递归调用
// 从本质上讲，函数的递归调用其实是一种特殊形式的循环