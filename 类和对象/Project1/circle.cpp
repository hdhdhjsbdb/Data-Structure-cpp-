#include"circle.h"

void Circle::setR(int r) //���ð뾶
{
	m_R = r;
}

void Circle::setCenter(Point center) //����Բ��
{
	m_center = center;
}

int Circle::getR() //��ȡ�뾶
{
	return m_R;
}

Point Circle::getCenter() //��ȡԲ��
{
	return m_center;
}
