#include<iostream>
using namespace std;

class Person
{
public:
	int m_Age;
	int* m_Height;
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int age, int height)
	{
		cout << "Person的有参数构造函数调用" << endl;
		m_Age = age;
		m_Height = new int(height);
	}

	//自己实现深拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person& p)
	{
		cout << "深拷贝构造函数调用\n";
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);
	}

	~Person()
	{
		//将堆区开辟的数据释放掉
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}
};

void test01()
{
	Person p1(18,180);
	cout << "p1的年龄为：" << p1.m_Age << endl<<"身高为："<<*p1.m_Height<<endl;
	Person p2(p1); //系统调用默认浅拷贝
	cout << "p2的年龄为：" << p2.m_Age << endl<<"身高为：" << *p2.m_Height << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}