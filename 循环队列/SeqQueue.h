#pragma once
#include<iostream>
#include<cassert>
using namespace std;
//ѭ�����е��ඨ��
template <class T>
class SeqQueue
{
public:
	SeqQueue(int sz = 20);//���캯��
	~SeqQueue() { delete[] elements; }//��������
	/**δ����ӣ������������*/
	bool EnQueue(T x);
	/**��δ���˳���ͷԪ��*/
	bool DeQueue(T& x);
	/**��Ϊ��ͨ��x���ض�ͷԪ�ص�ֵ*/
	bool getFront(T& x)const;
	void makeEmpty() 
	{//��ͷ�Ͷ�βָ����0
		front = rear = 0;
	}
	bool IsEmpty()const
	{//�жϿշ�
		return front == rear;
	}
	bool IsFull()const
	{//�ж�����
		return (rear + 1) % maxSize == front;
	}
	int getSize()const
	{//�����Ԫ�ظ���
		return (rear - front + maxSize) % maxSize;//���⸺�����
	}
	friend ostream& operator<< <>(ostream& os, const SeqQueue<T>& Q);//�����������
protected:
	int rear, front;//��β���ͷָ��
	T* elements;//��Ŷ���Ԫ�ص�����
	int maxSize;//��������Ԫ�ظ���
};

template<class T>
inline SeqQueue<T>::SeqQueue(int sz) :front(0),rear(0),maxSize(sz+1)
{
	elements = new T[maxSize];//�������пռ�
	assert(elements != NULL);
}

template<class T>
inline bool SeqQueue<T>::EnQueue(T x)
{
	if (IsFull()) return false;
	elements[rear] = x;
	rear = (rear + 1) % maxSize;//��βָ���1
	return true;
}

template<class T>
inline bool SeqQueue<T>::DeQueue(T& x)
{
	if (IsEmpty()) return false;
	x = elements[front];
	front = (front + 1) % maxSize;//��ͷָ���1
	return true;
}

template<class T>
inline bool SeqQueue<T>::getFront(T& x) const
{
	if (IsEmpty()) return false;
	x = elements[front];
	return true;
}

template <class T>
ostream& operator<<(ostream& os, const SeqQueue<T>& Q)
{
	os << "front=" << Q.front << " , " << "rear=" << Q.rear << endl;
	os << "�������� " << Q.getSize() << " ��Ԫ��" << endl;
	for (int i = Q.front; i != Q.rear; i = (i + 1) % Q.maxSize)
	{
		os << Q.elements[i] << " ";
	}
	os << endl;
	return os;
}

