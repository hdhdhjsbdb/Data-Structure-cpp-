#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//公共权限
	string m_Name;
protected:
	//保护权限
	string m_car;
private:
	//私有权限
	int m_password;
};

int main()
{
	Person p1;
	system("pause");
	return 0;
}