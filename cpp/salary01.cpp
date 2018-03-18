// 工资程序 V1.0
#include <iostream>
#include <climits>    // 为了使用整数最值宏INT_MAX，INT_MIN

using namespace std; 

int main()
{
    // 定义数组的最大数据元素量，表示这个程序最多可以处理100000个工资数据
    const int MAX = 100000; 
    // 定义数组并初始化，这个数组可以包含100000个int类型工资数据
    int arrSalary[MAX] = {0};
   
    // 定义记录工资总值、最小值和最大值的变量
    // 因为min和max用于记录最小值和最大值，所以分别将其初始化为int类型数据的最大值和最小值
    int nTotal = 0;
    int min = INT_MAX ;		//2147483647
    int max = INT_MIN ;		//-2147483648

    // 输入的有效工资数据个数，计算平均工资和查询工资时需要 
    int nCount = 0;
    // 利用for循环结构，重复执行输入动作，完成多个工资数据的输入
    for(int i = 0; i < MAX; ++i)  
    {
         // 提示用户输入
         cout<<"请输入"<<i<<"号员工的工资（-1表示输入结束）："<<endl;
         // 将输入的数据保存到arrSalary数组的第i个数据元素
         cin>>arrSalary[i];
   
         // 利用条件结构，检查是否输入了表示结束的特殊值
         if(-1 == arrSalary[i] )
         {
             // 输入结束，输出统计结果
             cout<<"工资输入结束，一共输入了"<<nCount<<"个工资数据。"<<endl;
             // 如果输入的数据个数不为0，输出统计信息
            if(0 != nCount)
            {
                 cout<<"其中，"<<endl;
                 cout<<"最大值是"<<max<<endl;
                 cout<<"最小值是"<<min<<endl;
                 // 计算平均工资
                 float fAver = (float)nTotal/nCount;
                 cout<<"平均工资是"<<fAver<<endl;
             }
             // 输入结束，用break关键字结束整个输入循环
             break;
         }
         
         // 如果是正常输入，则进行常规处理
         ++nCount;    // 工资数据个数加1
        // 累加工资总额
         nTotal += arrSalary[i];
         // 更新工资的最大值和最小值
         if(arrSalary[i] < min) // 如果新输入的数值比已知的最小值min小
             min = arrSalary[i];// 用新输入的值取代旧的最小值
         if(arrSalary[i] > max) // 最大值相似处理
             max = arrSalary[i];
    }

    // 输入过程结束，开始查询过程
    // 如果数据个数为0，表示没有输入数据，不再进行查询而直接结束
    if(0 == nCount)
    {
        cout<<"没有工资数据，无法进行查询。感谢使用！"<<endl;
        return 0;  // 直接结束程序
    }

    // 拥有工资数据，构造无限循环进行工资查询，在循环中根据条件退出循环
    while(true)
    {
        // 输入的员工序号
        int n = 0;
        // 提示用户输入
        cout<<"请输入要查询的员工序号（0-"<<nCount-1<<"，-1表示结束查询）："<<endl;

        // 获取用户输入的员工序号并保存到n
        cin>>n;
        // 对用户输入进行检查
        if(-1 == n) // 是否输入了表示结束的特殊值
        {
             // 查询结束，用break关键字结束整个查询循环
             cout<<"查询完毕，感谢使用！"<<endl;
             break;
        }
        else if(n < 0 || n >= nCount) // 是否超出序号范围
        {
             // 提示用户输入错误
             cout<<"输入的序号"<<n<<"超出了序号范围0-"<<nCount-1<<"，请重新输入。"<<endl;
             // 输入的序号超出范围， 用continue结束本次循环，开始下一次循环
             continue;
        }

        // 输入合法，输出用户查询的员工工资
        cout<<"员工序号："<<n<<endl;
        // 这里用输入的员工序号作为数组下标，直接得到对应位置上的工资数据
        cout<<"员工工资："<<arrSalary[n]<<endl;
    }

    return 0;
}
