#pragma once
#include<iostream>
#include"point.h"
using namespace std;

class Circle  //创建一个圆类
{
private:
	int m_R;
	Point m_center;
public:
	void setR(int r); //设置半径
	void setCenter(Point center); //设置圆心
	int getR(); //获取半径
	Point getCenter(); //获取圆心
};
