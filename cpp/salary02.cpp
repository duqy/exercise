// 工资程序 V2.0
#include <iostream>
#include <climits>    // 为了使用整数最值宏INT_MAX，INT_MIN

using namespace std; 

int InputSalary(int* pArr, const int MAX_NUM)
{
    if(MAX_NUM <= 0 || nullptr == pArr)
    {
        return 0;
    }

    int nIndex = 0;
    int nTemp = 0;

    do
    {
        cout<<"请输入第"<<nIndex<<"员工工资："<<endl;
        cin>>nTemp;

        if(nTemp <= 0)
        {
            break;
        }

        pArr[nIndex] = nTemp;
        ++nIndex;
    } while(nIndex < MAX_NUM);

    return nIndex;
}

float GetAverage(int* pArr, const int nCount)
{
    if(nCount <= 0 || nullptr == pArr)
    {
        return 0;
    }

    int nTotal = 0;
    for (int i = 0; i < nCount; ++i)
    {
        nTotal += pArr[i];
    }

    return (float)nTotal/nCount;

}

int main()
{
    const int NUM = 3;
    int arrSalary[NUM] = {0};

    int nCount = InputSalary(arrSalary, NUM);

    float fAver = GetAverage(arrSalary, nCount);

    cout<<"平均工资："<<fAver<<endl;

    return 0;
}
