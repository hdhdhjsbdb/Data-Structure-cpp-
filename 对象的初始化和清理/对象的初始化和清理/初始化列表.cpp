#include<iostream>
using namespace std;
//初始化列表
class person
{
public:
	int m_A, m_B, m_C;

	//初始化列表初始化属性
	person(int a,int b,int c) :m_A(a), m_B(b), m_C(c)
	{

	}
};

void test01()
{
	person p1(1,2,3);
	cout << "m_A= " << p1.m_A << endl;
	cout << "m_B= " << p1.m_B << endl;
	cout << "m_C= " << p1.m_C << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}