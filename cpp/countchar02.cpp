#include <iostream>
#include <cstring>

unsing namespace std;

int CountChar(const char* str, const char c)
{
    int nTotal = 0;

    while(nullptr != (strchar(str, c)))
    {
        ++nTotal;
        ++str;  // 字符串往后移动，开始下一次循环
    }

    return nTotal;
}

int int main()
{
    char str[] = "Thought is a seed";
    char c = 'h';

    int nCount = CountChar(str, c);

    cout<<"字符\'"<<c<<"\'在"<<str<<"中出现了"<<nCount<<"次"<<endl;
    
    return 0;
}

// 将递归改为循环