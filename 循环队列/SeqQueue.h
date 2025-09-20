#pragma once
#include<iostream>
#include<cassert>
using namespace std;
//循环队列的类定义
template <class T>
class SeqQueue
{
public:
	SeqQueue(int sz = 20);//构造函数
	~SeqQueue() { delete[] elements; }//析构函数
	/**未满入队，否则溢出处理*/
	bool EnQueue(T x);
	/**队未空退出队头元素*/
	bool DeQueue(T& x);
	/**不为空通过x返回队头元素的值*/
	bool getFront(T& x)const;
	void makeEmpty() 
	{//队头和队尾指针置0
		front = rear = 0;
	}
	bool IsEmpty()const
	{//判断空否
		return front == rear;
	}
	bool IsFull()const
	{//判断满否
		return (rear + 1) % maxSize == front;
	}
	int getSize()const
	{//求队列元素个数
		return (rear - front + maxSize) % maxSize;//避免负数情况
	}
	friend ostream& operator<< <>(ostream& os, const SeqQueue<T>& Q);//输出操作重载
protected:
	int rear, front;//队尾与队头指针
	T* elements;//存放队列元素的数组
	int maxSize;//最大可容纳元素个数
};

template<class T>
inline SeqQueue<T>::SeqQueue(int sz) :front(0),rear(0),maxSize(sz+1)
{
	elements = new T[maxSize];//创建队列空间
	assert(elements != NULL);
}

template<class T>
inline bool SeqQueue<T>::EnQueue(T x)
{
	if (IsFull()) return false;
	elements[rear] = x;
	rear = (rear + 1) % maxSize;//队尾指针加1
	return true;
}

template<class T>
inline bool SeqQueue<T>::DeQueue(T& x)
{
	if (IsEmpty()) return false;
	x = elements[front];
	front = (front + 1) % maxSize;//队头指针加1
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
	os << "队列中有 " << Q.getSize() << " 个元素" << endl;
	for (int i = Q.front; i != Q.rear; i = (i + 1) % Q.maxSize)
	{
		os << Q.elements[i] << " ";
	}
	os << endl;
	return os;
}

