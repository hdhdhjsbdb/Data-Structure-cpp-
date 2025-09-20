#include<iostream>
#include<string>
using namespace std;
// 类对象作为类成员

class Phone
{
public:
	string m_PName;
	Phone(string PName)
	{
		m_PName = PName;
	}

	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}
};

class Person
{
public:
	string m_name;
	Phone m_Phone;
	Person(string name, string PName):m_name(name),m_Phone(PName)
	{
		// 初始化列表方法
	}

	~Person()
	{
		cout << "Person 的析构函数调用" << endl;
	}
};

//当其他类对象作为本类成员，构造时先构造类对象，再构造自身
//析构顺序和构造顺序相反
void test01()
{
	Person p("张三", "iphone");
	cout << "姓名：" << p.m_name << endl << "手机：" << p.m_Phone.m_PName << endl;
}

int main() 
{
	test01();


	system("pause");
	return 0;
}