#include<iostream>
#include<string>
using namespace std;

//��Ա��������Ϊ˽��
class person
{
private:
	string m_Name; //���� �ɶ���д
	int m_Age = 18; //���� ֻ��
	string m_Idol; //ż�� ֻд
public:
	void setName(string name)//��������
	{
		m_Name = name;
	}
	string getName()//��ȡ����
	{
		return m_Name;
	}

	void setAge(int Age) //������Ч����֤
	{
		if (Age < 0 || Age>150)
		{
			cout << "���䳬�������뷶Χ��" << endl;
			return;
		}
		m_Age = Age;
	}

	int getAge()//��ȡ����
	{
		return m_Age;
	}
	void setIdol(string Idol)//����ż��
	{
		m_Idol = Idol;
	}
};

int main()
{
	person p1;
	p1.setName("����");
	p1.setIdol("kunkun");
	cout << "������" << p1.getName() << endl
		<<"���䣺"<<p1.getAge()<<endl;
	p1.setAge(50);
	cout << "������" << p1.getName() << endl
		<< "���䣺" << p1.getAge() << endl;
	system("pause");
	return 0;
}