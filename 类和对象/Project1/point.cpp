#include"point.h"

void Point::setPoint(int x, int y) //����x��y����
{
	m_x = x;
	m_y = y;
}

int Point::getX()
{
	return m_x;
}

int Point::getY()
{
	return m_y;
}
