#include<iostream>
#include<string>
using namespace std;

//���캯���ķ��༰����
class Person
{
public:
	int age;
	string name;
public:
	//�޲ι��캯��
	Person()
	{
		cout << "Person���޲ι��캯������" << endl;
	}

	//�вι��캯��
	Person(int a)
	{
		age = a;
		cout << "Person���вι��캯������" << endl;
	}

	//�������캯��
	Person(const Person &p) //���������õķ�ʽ����
	{
		//������������ϵ��������Զ����뵽�ҵ�����
		age = p.age;
		name = p.name;
		cout << "Person�Ŀ������캯���ĵ���" << endl;
	}
	//��������
	~Person()
	{
		cout << "Person��������������" << endl;
	}
};

//����
void test01()
{
	//1�����ŷ�
	Person p1; //Ĭ�Ϲ��캯���ĵ���
	Person p2(10);//�вι��캯���ĵ���
	Person p3(p2);//�������캯���ĵ���
	cout << "p2������Ϊ��" << p2.age << endl;
	cout << "p3������Ϊ��" << p3.age << endl;
	//ע���������Ĭ�Ϲ��캯��ʱ����Ҫ�ӣ���
	// 
	//2����ʾ��
	Person p4 = Person(10);
	Person p5 = Person(p2);
	//3����ʽת����
	Person p6 = 10;
	Person p7 = p4;

}

int main()
{
	test01();


	system("pause");
	return 0;
}