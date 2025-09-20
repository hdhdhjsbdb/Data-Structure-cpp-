#include<iostream>
#include<cmath>
#include"point.h"
#include"circle.h"
using namespace std;
//设计一个圆类，和一个点类，计算点和圆的关系

//class Point //创建一个点类
//{
//private:
//	int m_x;
//	int m_y;
//public:
//	void setPoint(int x, int y) //设置x，y坐标
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

//class Circle  //创建一个圆类
//{
//private:
//	int m_R;
//	Point m_center;
//public:
//	void setR(int r) //设置半径
//	{
//		m_R = r;
//	}
//
//	void setCenter(Point center) //设置圆心
//	{
//		m_center = center;
//	}
//
//	int getR() //获取半径
//	{
//		return m_R;
//	}
//
//	Point getCenter() //获取圆心
//	{
//		return m_center;
//	}
//};

void isIncircle(Point &p, Circle &c) //判断点和圆的关系
{
	int distance = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);
	int Rdis = pow(c.getR(),2);
	if (distance == Rdis)
	{
		cout << "点在圆上" << endl; 
	}
	else if (distance > Rdis)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
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