#include<iostream>
using namespace std;

void func(int &val)
{
	cout << "val(�ǳ���) = " << val << endl;
}

void func(const int &val)
{
	cout << "val(����) = " << val << endl;
}

int main()
{
	int a = 10;
	func(a);
	func(10);


	system("pause");
	return 0;
}