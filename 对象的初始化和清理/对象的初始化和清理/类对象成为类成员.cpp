#include<iostream>
#include<string>
using namespace std;
// �������Ϊ���Ա

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
		cout << "Phone��������������" << endl;
	}
};

class Person
{
public:
	string m_name;
	Phone m_Phone;
	Person(string name, string PName):m_name(name),m_Phone(PName)
	{
		// ��ʼ���б���
	}

	~Person()
	{
		cout << "Person ��������������" << endl;
	}
};

//�������������Ϊ�����Ա������ʱ�ȹ���������ٹ�������
//����˳��͹���˳���෴
void test01()
{
	Person p("����", "iphone");
	cout << "������" << p.m_name << endl << "�ֻ���" << p.m_Phone.m_PName << endl;
}

int main() 
{
	test01();


	system("pause");
	return 0;
}