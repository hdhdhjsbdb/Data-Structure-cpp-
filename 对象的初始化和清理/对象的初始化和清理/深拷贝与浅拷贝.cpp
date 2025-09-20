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
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	Person(int age, int height)
	{
		cout << "Person���в������캯������" << endl;
		m_Age = age;
		m_Height = new int(height);
	}

	//�Լ�ʵ��������캯�������ǳ��������������
	Person(const Person& p)
	{
		cout << "������캯������\n";
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);
	}

	~Person()
	{
		//���������ٵ������ͷŵ�
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person��������������" << endl;
	}
};

void test01()
{
	Person p1(18,180);
	cout << "p1������Ϊ��" << p1.m_Age << endl<<"���Ϊ��"<<*p1.m_Height<<endl;
	Person p2(p1); //ϵͳ����Ĭ��ǳ����
	cout << "p2������Ϊ��" << p2.m_Age << endl<<"���Ϊ��" << *p2.m_Height << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}