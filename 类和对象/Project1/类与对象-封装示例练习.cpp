#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	string m_name; //����
	int student_num; //ѧ��

	void showStudent()
	{
		cout << "������" << m_name << endl << "ѧ�ţ�" << student_num << endl;
	}

	//��������ֵ
	void setName(string name)
	{
		m_name = name;
	}
	//��������ֵ
	void setID(int ID)
	{
		student_num = ID;
	}
};

int main()
{
	//ʵ��������
	Student s1, s2;
	//s1.m_name = "����";
	s1.setName("����");
	//s1.student_num = 2150945;
	s1.setID(2150945);
	s1.showStudent();

	s1.m_name = "����";
	s1.student_num = 2256984;
	s1.showStudent();

	system("pause");
	return 0;
}