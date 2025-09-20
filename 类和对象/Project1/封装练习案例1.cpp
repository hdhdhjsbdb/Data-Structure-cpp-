#include<iostream>
using namespace std;

//设计一个立方体类，求出立方体的面积和体积
class Cube
{
private:
	float m_L, m_W, m_H;
public:
	void set(float L, float W, float H)
	{
		m_L = L;
		m_W = W;
		m_H = H;
	}

	float getS()
	{
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	float getV()
	{
		return m_L * m_W * m_H;
	}

};

int main()
{
	Cube c1;
	c1.set(10, 10, 10);
	cout << "立方体的表面积为：" << c1.getS() << endl;
	cout << "立方体的体积为：" << c1.getV() << endl;
	system("pause");
	return 0;
}