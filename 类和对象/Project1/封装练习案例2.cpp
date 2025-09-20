#include<iostream>
#include<cmath>
#include"point.h"
#include"circle.h"
using namespace std;
//���һ��Բ�࣬��һ�����࣬������Բ�Ĺ�ϵ

//class Point //����һ������
//{
//private:
//	int m_x;
//	int m_y;
//public:
//	void setPoint(int x, int y) //����x��y����
//	{
//		m_x = x;
//		m_y = y;
//	}
//
//	int getX()
//	{
//		return m_x;
//	}
//
//	int getY()
//	{
//		return m_y;
//	}
//};

//class Circle  //����һ��Բ��
//{
//private:
//	int m_R;
//	Point m_center;
//public:
//	void setR(int r) //���ð뾶
//	{
//		m_R = r;
//	}
//
//	void setCenter(Point center) //����Բ��
//	{
//		m_center = center;
//	}
//
//	int getR() //��ȡ�뾶
//	{
//		return m_R;
//	}
//
//	Point getCenter() //��ȡԲ��
//	{
//		return m_center;
//	}
//};

void isIncircle(Point &p, Circle &c) //�жϵ��Բ�Ĺ�ϵ
{
	int distance = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);
	int Rdis = pow(c.getR(),2);
	if (distance == Rdis)
	{
		cout << "����Բ��" << endl; 
	}
	else if (distance > Rdis)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

int main()
{
	Point p1, p2;
	Circle c;
	p1.setPoint(0, 0);
	p2.setPoint(0, 2);
	c.setCenter(p1);
	c.setR(2);

	isIncircle(p2, c);

	system("pause");
	return 0;
}