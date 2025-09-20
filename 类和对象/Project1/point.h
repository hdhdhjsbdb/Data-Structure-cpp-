#pragma once //防止头文件重复包含
#include<iostream>
using namespace std;

class Point //创建一个点类
{
private:
	int m_x;
	int m_y;
public:
	void setPoint(int x, int y); //设置x，y坐标
	int getX();
	int getY();
};