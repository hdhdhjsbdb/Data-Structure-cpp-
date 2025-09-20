#include<iostream>
#include<string>
using namespace std;

//成员属性设置为私有
class person
{
private:
	string m_Name; //姓名 可读可写
	int m_Age = 18; //年龄 只读
	string m_Idol; //偶像 只写
public:
	void setName(string name)//设置姓名
	{
		m_Name = name;
	}
	string getName()//读取姓名
	{
		return m_Name;
	}

	void setAge(int Age) //年龄有效性验证
	{
		if (Age < 0 || Age>150)
		{
			cout << "年龄超过可输入范围！" << endl;
			return;
		}
		m_Age = Age;
	}

	int getAge()//读取年龄
	{
		return m_Age;
	}
	void setIdol(string Idol)//设置偶像
	{
		m_Idol = Idol;
	}
};

int main()
{
	person p1;
	p1.setName("张三");
	p1.setIdol("kunkun");
	cout << "姓名：" << p1.getName() << endl
		<<"年龄："<<p1.getAge()<<endl;
	p1.setAge(50);
	cout << "姓名：" << p1.getName() << endl
		<< "年龄：" << p1.getAge() << endl;
	system("pause");
	return 0;
}