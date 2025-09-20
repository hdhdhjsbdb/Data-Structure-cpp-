#include<iostream>
using namespace std;

//拷贝函数调用时机

class Person
{
public:
	int m_Age;

public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int age)
	{
		cout << "Person的有参数构造函数调用" << endl;
		m_Age = age;
	}

	Person(const Person& p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);
}

//2、值传递的方式给函数参数传值
void doWork(Person p)
{

}


void test02()
{
	Person p;
	doWork(p);
}

//3、值方式返回局部对象
Person doWork2()
{
	Person p1;
	return p1;
}

void test03()
{
	Person p = doWork2();
}
int main()
{
	//test01();
	//test02();
	test03();

	system("pause");
	return 0;
}