#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	string m_name; //姓名
	int student_num; //学号

	void showStudent()
	{
		cout << "姓名：" << m_name << endl << "学号：" << student_num << endl;
	}

	//给姓名赋值
	void setName(string name)
	{
		m_name = name;
	}
	//给姓名赋值
	void setID(int ID)
	{
		student_num = ID;
	}
};

int main()
{
	//实例化对象
	Student s1, s2;
	//s1.m_name = "张三";
	s1.setName("张三");
	//s1.student_num = 2150945;
	s1.setID(2150945);
	s1.showStudent();

	s1.m_name = "李四";
	s1.student_num = 2256984;
	s1.showStudent();

	system("pause");
	return 0;
}