#pragma once
#include<iostream>
#include<cassert>
using namespace std;
const int maxStack = 20;
const int stackIncrement = 20;//ջ���ʱ��չ�Ŀռ�����
template <class T>
class SeqStack
{
public:
	SeqStack(int sz = maxStack);
	~SeqStack() { delete[]elements; }
	bool IsFull()const { return(top == maxSize - 1) ? true : false; }
	bool IsEmpty()const { return(top == -1) ? true : false; }
	void Push(T& x); //ջ����������������x�嵽ջ��
	bool Pop(T& x);//ջ������ջ������false�������˵�ջ��Ԫ�أ�����true
	bool getTop(T& x)const;//ջ�շ���false�����򷵻�true����ͨ��x�õ�ջ��Ԫ��
	int getSize() { return top + 1; } //����ջ��Ԫ�ظ���
	void MakeEmpty() { top = -1; }//���ջ����
	friend ostream& operator << (ostream& os, SeqStack<T>& s)
	{
		os << "top=" << s.top << endl;
		for (int i = 0; i <= s.top; i++)
		{
			os << s.elements[i] << " ";
		}
		os << endl;
		return os;
	}
private:
	T* elements; //���ջ��Ԫ�ص�ջ����
	int top;//ջ��ָ��
	int maxSize;//ջ�������ɵ�Ԫ�ظ���
	void overflowProcess();//ջ�������
};

template<class T>
SeqStack<T>::SeqStack(int sz) :top(-1), maxSize(sz)
{//����һ�����ߴ�Ϊsz�Ŀ�ջ
	elements = new T[maxSize];
	assert(elements != nullptr); //������������ִ��
}

template<class T>
void SeqStack<T>::Push(T& x)
{
	if (IsFull()) overflowProcess();
	elements[++top] = x; //ջ��ָ���1�ٽ�ջ
}

template<class T>
bool SeqStack<T>::Pop(T& x)
{
	if (IsEmpty()) return false;
	x = elements[top--];
	return true;
}

template<class T>
bool SeqStack<T>::getTop(T& x)const
{
	if (IsEmpty()) return false;
	x = elements[top];
	return true;
}

template<class T>
void SeqStack<T>::overflowProcess()
{//ջ�������
	T* newArray = new T[maxSize + stackIncrement];
	if (newArray == NULL)
	{
		cerr << "�����ڴ�ʧ��" << endl;
		exit(1);
	}
	for (int i = 0; i <= top; i++)
	{
		newArray[i] = elements[i];
	}
	maxSize = maxSize + stackIncrement;
	delete[]elements;
	elements = newArray;
}


