#pragma once
#include<iostream>
#include"point.h"
using namespace std;

class Circle  //����һ��Բ��
{
private:
	int m_R;
	Point m_center;
public:
	void setR(int r); //���ð뾶
	void setCenter(Point center); //����Բ��
	int getR(); //��ȡ�뾶
	Point getCenter(); //��ȡԲ��
};
