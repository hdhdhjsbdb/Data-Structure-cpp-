#include<iostream>
using namespace std;

//���һ���������࣬������������������
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
	cout << "������ı����Ϊ��" << c1.getS() << endl;
	cout << "����������Ϊ��" << c1.getV() << endl;
	system("pause");
	return 0;
}