// 工资程序 V3.0
#include <iostream>
#include <fstream>    // 为了读写文件
#include <string>
#include <climits>    // 为了使用整数最值宏INT_MAX，INT_MIN

using namespace std;

// 全局的工资数据文件名，使用一个不可修改的常量字符串表示
const string strFileName = "SalaryData.txt";

// 从数据文件读取工资数据到arrSalary数组
int Read(int* arrSalary, int nCount)
{
    int i = 0;   // 当前员工序号
    // 打开工资数据文件SalaryData.txt，用于读入数据
    // 这个文件应该在exe文件所在的相同目录下
    ifstream in(strFileName);
    if(in.is_open())   // 如果成功打开数据文件
    {
        // 构造一个while循环读取文件中的工资数据
        // 如果读取的数据个数i小于数组的容量nCount，则继续读取
        while(i < nCount)
        {
            // 将读取的数据保存到arrSalary[i]
            in>>arrSalary[i];
            // 对读取结果进行判断，看是否读取到了文件结束
            // 如果到达文件结尾，则用break结束读取循环
            if(!(in))
            {
                break;
            }
            ++i;
        }
        // 读取完毕，关闭文件
        in.close();
    }
    // 输出读取结果，返回读取的数据个数
    cout<<"读取"<<i<<"个工资数据"<<endl;
    return i;
}


// 将arrSalary数组中的工资数据写入数据文件
void Write(int* arrSalary, int nCount)
{
    // 创建或打开工资数据文件SalaryData.txt用于输出
    // 输出完成后，这个文件将出现在exe文件所在的目录
    ofstream o(strFileName);
    if(o.is_open())
    {
        for (int i = 0; i < nCount; ++i) {
            o<<arrSalary[i]<<endl;   // 每行一个数据
        }
        o.close();
    }
}

// 获取工资数组中的最大值
int GetMax(int* arrSalary, int nCount)
{
    int nMax = INT_MIN;    // 初始化为int类型的最小值
    for (int i = 0; i < nCount; ++i) {
        if(arrSalary[i] > nMax)
        {
            nMax = arrSalary[i];
        }
    }
    return nMax;
}

// 获取工资数组中的最小值
int GetMin(int* arrSalary, int nCount)
{
    int nMin = INT_MAX;
    for (int i = 0; i < nCount; ++i) {
        if(arrSalary[i] < nMin)
        {
            nMin = arrSalary[i];
        }
    }
    return nMin;
}

// 计算数组中所有数据的平均值
float GetAver(int* arrSalary, int nCount)
{
    int nTotal = 0;
    for (int i = 0; i < nCount; ++i) {
        nTotal += arrSalary[i];
    }
    if(0 != nTotal)
        return (float)nTotal/nCount;
    else
        return 0.0f;
}

// 手工输入数据
//arrSalary工资数组首地址，nMax数组容量，nIndex数组实际容量
int Input(int* arrSalary, int nMax, int nIndex)
{
    // 用数组中已有的数据作为输入的起点
    int i = nIndex;    // 在for循环前初始化，因为在for之后还需要用到
    for (int i = 0; i < nMax; ++i) {
        cout<<"请输入"<<i<<"号员工的工资(-1表示输入结束)："<<endl;
        int n = 0;
        cin>>n;

        // 检查输入是否合法
        if(cin)
        {
            arrSalary[i] = n;
        }
        else
        {
            cout<<"输入有误，请重新输入"<<endl;
            // 清理cin的输入标志位以重新输入
            cin.clear();
            // 清空输入缓冲区
            cin.sync();
            --i;    //  将输入序号退后一个
            continue;    // 直接开始下一次循环
        }
        // 检查是否输入结束
        if(-1 == arrSalary[i])
        {
            break;
        }
    }
    return i;    // 返回当前数组中共有的数据个数
}

// 查询工资数据
void Find(int* arrSalary, int nCount)
{
    while (true) {  // 构建无限循环进行工资查询
        int n = 0;
        cout<<"请输入要查询的员工序号(0-"<<nCount-1<<",-1表示结束查询)："<<endl;
        cin>>n;

        // 对用户输入检查
        if (!cin) {
            cout<<"输入有误，请重新输入"<<endl;
            // 清理cin的输入标志位以重新输入
            cin.clear();
            // 清空输入缓冲区
            cin.sync();
            continue;
        }
        else if (-1 == n) {  // 检查查询是否结束
            // 查询结束，用break结束循环
            cout<<"查询完毕，感谢使用！"<<endl;
            break;
        }
        else if (n<0 || n>nCount) {  // 检查输入是否超出序号范围
            // 输入序号超出范围，用contunue开始下一次循环
            cout<<"输入的序号"<<n<<"超出了序号范围(0-"<<nCount-1<<"),请重新输入。"<<endl;
            continue;  // 开始下一次查询
        }
        // 输入合法，输出用户查询的员工工资
        cout<<"员工序号："<<n<<endl;
        cout<<"员工工资："<<arrSalary[n]<<endl;
    }
}

int main()
{
    const int MAX = 100000;
    int arrSalary[MAX] = {0};

    // 首先从数据文件读取已经保存的数据
    int nCount = Read(arrSalary, MAX);
    // 然后手工继续输入工资数据
    nCount = Input(arrSalary, MAX, nCount);

    // 对输入的工资数据进行统计
    cout<<"输入完毕，一共有"<<nCount<<"个工资数据"<<endl;
    cout<<"最大值："<<GetMax(arrSalary, nCount)<<endl;
    cout<<"最小值："<<GetMin(arrSalary, nCount)<<endl;
    cout<<"平均值："<<GetAver(arrSalary, nCount)<<endl;

    // 对工资数据进行查询
    Find(arrSalary, nCount);

    // 查询结束，钭工资数据保存到数据文件，以备下次使用
    Write(arrSalary, nCount);

    return 0;
}

/*
工资程序

数据输入
    手工输入
    文件输入

数据处理
    最大值
    最小值
    平均值
    查询工资

数据输出
    输出到文件
*/