#include<iostream>
#include<string>
using namespace std;

//构造函数的分类及调用
class Person
{
public:
	int age;
	string name;
public:
	//无参构造函数
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}

	//有参构造函数
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}

	//拷贝构造函数
	Person(const Person &p) //常量、引用的方式传入
	{
		//将传入的人身上的所有属性都传入到我的身上
		age = p.age;
		name = p.name;
		cout << "Person的拷贝构造函数的调用" << endl;
	}
	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

//调用
void test01()
{
	//1、括号法
	Person p1; //默认构造函数的调用
	Person p2(10);//有参构造函数的调用
	Person p3(p2);//拷贝构造函数的调用
	cout << "p2的年龄为：" << p2.age << endl;
	cout << "p3的年龄为：" << p3.age << endl;
	//注意事项：调用默认构造函数时，不要加（）
	// 
	//2、显示法
	Person p4 = Person(10);
	Person p5 = Person(p2);
	//3、隐式转换法
	Person p6 = 10;
	Person p7 = p4;

}

int main()
{
	test01();


	system("pause");
	return 0;
}