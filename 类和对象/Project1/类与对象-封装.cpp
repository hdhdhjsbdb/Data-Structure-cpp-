#include<iostream>
using namespace std;

const double PI = 3.1415926;

//���һ��Բ�࣬����Ԫ���ܳ�
class Circle
{
	//����Ȩ��
public:
	//����
	int m_r;

	//��Ϊ����ȡԲ���ܳ�
	double calculateZC()
	{
		return 2 * PI * m_r;
	}
};



int main()
{
	//ʵ������ͨ��Բ�ഴ��һ�������Բ������
	Circle c1;
	//��Բ��������Խ��и�ֵ
	c1.m_r = 10;
	//���Բ���ܳ�
	cout << "Բ���ܳ�Ϊ��" << c1.calculateZC() << endl;

	system("pause");
	return 0;
}