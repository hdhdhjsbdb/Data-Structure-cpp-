#pragma once //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;

class Point //����һ������
{
private:
	int m_x;
	int m_y;
public:
	void setPoint(int x, int y); //����x��y����
	int getX();
	int getY();
};