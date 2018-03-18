#include <iostream>

using namespace std;

int main()
{
    cout<<"请输入你的分数："<<endl;
    // 保存输入分数的int类型变量
    int nScore = 0;
    // 输入分数
    cin>>nScore;
    // 保存考试通过与否的bool类型变量
    // 默认状态为false，表示未通过
    bool bPass = false;
    // 用条件结构进行逻辑判断，判断输入的分数是否大于等于60
    if(nScore >= 60)
    {
        //如果输入的分数大于等于60，则赋值为True，表示通过
        //否则继续保留其初始值false，表示未通过
        bPass = true;
    }

    // 在条件结构中，根据bPass的取值不同，对程序的执行路径进行控制
    if (bPass) {
        //如果bPass的值为true,输出考试通过
        cout<<"恭喜，你通过了考试"<<endl;
    }
    else {
        // 如果bPass的值为false,输出考试未通过
        cout<<"很遗憾，你未通过考试"<<endl;
    }

    return 0;
}

