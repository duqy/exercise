#include <ctime> // 使用其中的时间函数
#include <string> // 使用字符串对象
#include <iostream> // 屏幕输入输出
#include <fstream> // 文件输入输出
#include <climits> // 引入 INT_MAX

#include <vector> // 为了使用 vector 容器
#include <algorithm> // 为了使用 count_if()算法

using namespace std;

/*
用 STL中的容器和算法对原来的工资程序进行改写
用可以动态改变大小的 vector 容器来保存会动态增减的员工数据。容器的大小会随着数据的增减而动态变
化，不至于浪费内存资源，也不会出现空间不够的情况。同时，vector 容器提供了丰富的成员函数，
对数据的访问既便捷又安全。
用 STL中的 find_if()算法以及 max_element()算法代替了原来使用 for 循环遍历数组进行的查找，
这样只需要关心这些算法中最核心的业务逻辑，而无需关心 for 循环如何访问数组
*/


// 枚举员工的级别
enum EmpLevel
{
    enumOfficer = 1, // 高级员工
    enumStaff = 2 // 一般员工
};

// 员工类
class Employee
{
public:
    // 构造函数，根据员工的姓名和入职年份构造对象
    Employee(string strName,int nY)
        :m_strName(strName),m_nYear(nY) // 设定员工的姓名和入职年份
    {}
    // Employee 类的行为，这些行为都是供外界调用的接口，
    // 所以将其访问级别设定为 public
public:
    // 获得员工姓名
    string GetName() const
    {
        return m_strName;
    }
    // 获得员工入职年份
    int GetYear() const
    {
        return m_nYear;
    }
    // 获得员工级别
    EmpLevel GetLevel() const
    {
        return m_nLevel;
    }
    // 获得员工工资，因为这个行为同具体的员工类相关，
    // 不同的派生类有不同的行为（计算方法），所以在基类 Employee 中只是
    // 用纯虚函数表示接口，具体行为由其派生类实现
    virtual int GetSalary() = 0;
    // GetWorkTime()只是供自身和自己的派生类似用，所以将其
    // 访问级别设定为 protected
protected:
    // 获得在职时间，也就是现在年份减去入职年份
    int GetWorkTime() const
    {
        // 获得现在的年份
        time_t t = time(0);
        struct tm* now = localtime(&t);
        // time()函数获得的时间是以 1900 年为起点，所以这里需要
        // 加上 1900。同时，不满一年按照一年计算，所以最后要加 1
        return now->tm_year + 1900 - m_nYear + 1;
    }
    // Employee 类的属性
    // 因为这些属性也同样应当是其派生类具有的，需要由基类遗传给
    // 它的派生类，所以这里使用 protected 访问级别，允许其派生类继承这些属性
protected:
    string m_strName; // 姓名
    int m_nYear; // 入职年份
    EmpLevel m_nLevel; // 级别
};

// 高级员工类
class Officer : public Employee
{
public:
    // 构造函数
    // 直接调用基类 Employee 的构造函数，完成相同部分属性的构建
    Officer(string strName, int nY)
        :Employee(strName,nY)
    {
        // 进行派生类独有的构建工作，设定员工的特定级别
        m_nLevel = enumOfficer;
    }
public:
    // 对基类的纯虚函数进行重写，具体实现员工计算工资的行为
    virtual int GetSalary() override
    {
        // 对于高级员工，每年涨 5000 元工资
        return GetWorkTime()*5000;
    }
};

// 普通员工类
class Staff : public Employee
{
public:
    Staff(string strName, int nY)
        :Employee(strName,nY)
    {
        m_nLevel = enumStaff;
    }
public:
    // 不同的派生类对相同的行为有不同的实现，
    // 这就是类的多态机制的体现
    virtual int GetSalary() override
    {
        // 普通员工，每年涨 1000 元工资
        return GetWorkTime()*1000;
    }
};


// 定义 SalarySys 中数组的最大数据量，
// 也就是 SalarySys 最多能处理多少个员工数据
const int MAX = 100000;


// 用容器和算法改写后的 SalarySys 类
class SalarySys
{
public:
	// 使用 vector 容器保存数据，构造函数不需要对其进行初始化
	// 直接读取数据到容器即可
	SalarySys()
	: m_strFileName("SalaryData.txt")
	{
		Read(); // 直接读取数据
	}
	// 析构函数
	~SalarySys()
	{
		// 保存数据到文件
		Write();
		// 析构对象，释放内存
		// 使用序列 for 循环方便地访问容器中的 Employee*指针
		for(Employee* p : m_vecEmp)
		{
		delete p;
		}
		// 用 vector 容器的 clear()函数清空容器
		m_vecEmp.clear();
	}

private:
	// 读取数据，创建对象并保存到 vector 容器
	int Read()
	{
		// …
	}
	// 将 vector 容器中的数据写入文件
	void Write()
	{
		ofstream o(m_strFileName);
		if(o.is_open())
		{
			// 使用序列 for 循环遍历访问容器中的数据
			for(Employee* p : m_vecEmp)
			{
				o<<p->GetName()<<"\t"<<p->GetLevel()<<"\t"<<p->GetYear()<<endl;
			}
			o.close();
		}
	}
public:
	// 输入数据
	int Input()
	{
		cout<<"请输入员工信息（名字 等级 入职年份）"<<endl;
		cout<<"例如：Jiawei 1 1983，-1 表示输入结束"<<endl;
		while(true) // vector 不限制容量，所以可以使用无限循环构造输入循环
		{
			// 提示输入
			// 用 size()函数动态地获得 vector 容器中数据的个数
			cout<<"请输入"<<m_vecEmp.size()<<"号员工的信息："<<endl;
			// 根据输入的数据创建对象，并保存到 vector 容器
			string strName = "";
			int nL = 0;
			int nY = 0;
			cin>>strName>>nL>>nY;
			if(!cin) // 输入错误
			{
				cout<<"输入错误，请重新输入"<<endl;
				cin.clear();
				cin.sync();
				continue;
			}
			else
			{
				// 检查是否输入结束
				if("-1" == strName)
				{
					break; // 结束输入
				}
				// 根据输入数据创建对象，并添加到 vector 容器
				AddEmployee(strName,nL,nY);
			}
		}
		// 返回当前容器中的数据量
		return m_vecEmp.size();
	}

	Employee* GetMax()
	{
		// 使用 max_element()算法查找容器中的最大值
		// 代替原来的 for 循环遍历数组查找
		auto maxit = max_element(m_vecEmp.begin(), m_vecEmp.end(),
			// 配合算法使用的 Lambda 表达式，对算法进行自定义
			[](Employee* a, Employee* b) -> bool
			{
				return a->GetSalary() < b->GetSalary();
			});
		// 如果容器中有数据，返回找到的指向最大值的指针
		if(m_vecEmp.end() != maxit)
		{
			return (*maxit);
		}
		else // 如果容器中没有数据，返回 nullptr，表示没有最大值
		{
			return nullptr;
		}
	}

	// 查询员工工资
	void Find()
	{
		while(true)
		{
		string strName = "";
		// 输入提示
		cout<<"请输入要查询的员工名字（-1 表示结束查询）："<<endl;
		// 获取用户输入
		cin>>strName;
		if(!cin) // 如果发生输入错误
		{
			cout<<"输入错误，请重新输入"<<endl;
			cin.clear();
			cin.sync();
			continue;
		}
		else if("-1" == strName) // 是否输入结束
		{
			// 查询结束，用 break 结束查询循环
			cout<<"查询完毕，感谢使用！"<<endl;
			break;
		}
		// 使用 find_if 算法查找符合条件的员工数据
		// 代替原来的使用 for 循环遍历数组进行查找
		auto it = find_if(m_vecEmp.begin(),	m_vecEmp.end(),
		// 用 Lambda 表达式对查找条件进行自定义
		[=](Employee* emp) -> bool
		{
			// 如果当前员工姓名与用户输入的姓名相同
			return emp->GetName() == strName;
		});
			// 根据查找结果进行不同处理
			if(it!=m_vecEmp.end())
			{
				// 找到符合条件的员工，输出用户查询的员工工资
				cout<<"员工姓名："<<(*it)->GetName()<<endl;
				cout<<"员工工资："<<(*it)->GetSalary()<<endl;
			}
			else // 如果未找到，则提示重新输入
			{
				cout<<"无法找到名字为"<<strName<<"的员工"<<endl;
			}
		}
	}
private:
	// 根据数据创建相应的员工对象，并添加到 vector 容器
	void AddEmployee(const string& strName, const int nL, const int nY)
	{
		if(enumOfficer == nL)
			// 使用 push_back()函数将新创建的对象动态添加到 vector 容器
			m_vecEmp.push_back(new Officer(strName,nY));
		else if(enumStaff == nL)
			m_vecEmp.push_back(new Staff(strName,nY));
	}
private:
	const string m_strFileName;
	// 将原来固定大小的数组替换为可以动态改变大小的 vector 容器，节省资源
	// 同时省略了记录员工数据个数的成员变量 m_nCount
	vector<Employee*> m_vecEmp;
};


int main()
{
    // 第一次调用 getInstance()函数，唯一的 SalarySys 对象尚未创建，
    // 则创建相应的对象并返回指向这个对象的指针
    // 在构造函数中，它会首先去读取数据文件中的员工数据，
    // 完成“从文件读取”这一用例
    SalarySys* pSalarySys1 = SalarySys::getInstance();
    // …
    // 第二次调用 getInstance()函数，这时 SalarySys 的对象已经创建，
    // 则不再创建新对象而直接返回指向那个已创建对象的指针，保证对象的唯一性
    SalarySys* pSalarySys2 = SalarySys::getInstance();
    // …

    // 让用户输入数据，完成“手工输入”用例
    sys.Input();
    // 调用 SalarySys 的 GetMax()函数获得工资最高的员工对象，
    // 完成“计算最大值”用例
    Employee* pMax = sys.GetMax();
    if(nullptr != pMax)
    {
        cout<<"工资最高的员工是："<<endl;
        cout<<"名字："<<pMax->GetName()<<endl;
        cout<<"工资："<<pMax->GetSalary()<<endl;
    }
    // 调用 SalarySys 类的 Find()函数，完成“查询工资”用例
    sys.Find();
    // 最后，当 sys 对象析构的时候，会调用自己的 Write()函数，
    // 完成“输出数据到文件”用例

    // 释放已创建的对象, pSalarySys1 和 pSalarySys2 指向的是同一个对象，
    // 使用 pSalarySys1 或 pSalarySys2 释放这个对象是等效的，并只需要释放一次
    delete pSalarySys1;
    pSalarySys1 = pSalarySys2 = nullptr;
    return 0;
}

