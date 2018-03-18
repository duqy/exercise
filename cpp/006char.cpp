#include <iostream>

using namespace std;

int main()
{
    // 将‘A’对应的ASCII码值赋值给c
    // 等价于char c = 'A';
    char c = 65;
    // t表示不可见的控制字符‘\t'，表示一个Tab控制
    char t = '\t';

    // 循环输出26个大写字母字符
    for (int i = 0; i < 26; ++i) {
        // 输出c代表的字符
        cout<<c<<endl;
        c = c + 1;
    }

    // 定义一wchar_t类型的字符变量，并用一个中文字符对其赋值
    wchar_t cChs = L'曾';
    // 设置wcout输出对象的区域并输出中文字符
    wcout.imbue(locale("chs"));
    wcout<<cChs<<endl;
    
    return 0;
}

/*
wchar_t部分错误

This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.
terminate called after throwing an instance of 'std::runtime_error'
  what():  locale::facet::_S_create_c_locale name not valid
[Finished in 3.0s with exit code 3]
*/