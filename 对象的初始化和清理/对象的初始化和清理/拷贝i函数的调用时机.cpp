#include<iostream>
using namespace std;

//������������ʱ��

class Person
{
public:
	int m_Age;

public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	Person(int age)
	{
		cout << "Person���в������캯������" << endl;
		m_Age = age;
	}

	Person(const Person& p)
	{
		cout << "Person�Ŀ������캯������" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}
};

//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01()
{
	Person p1(20);
	Person p2(p1);
}

//2��ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p)
{

}


void test02()
{
	Person p;
	doWork(p);
}

//3��ֵ��ʽ���ؾֲ�����
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