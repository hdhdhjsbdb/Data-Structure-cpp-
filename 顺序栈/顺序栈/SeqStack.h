#pragma once
#include<iostream>
#include<cassert>
using namespace std;
const int maxStack = 20;
const int stackIncrement = 20;//栈溢出时扩展的空间增量
template <class T>
class SeqStack
{
public:
	SeqStack(int sz = maxStack);
	~SeqStack() { delete[]elements; }
	bool IsFull()const { return(top == maxSize - 1) ? true : false; }
	bool IsEmpty()const { return(top == -1) ? true : false; }
	void Push(T& x); //栈满则溢出处理，否则把x插到栈顶
	bool Pop(T& x);//栈空则不退栈，返回false；否则退掉栈顶元素，返回true
	bool getTop(T& x)const;//栈空返回false；否则返回true，并通过x得到栈顶元素
	int getSize() { return top + 1; } //返回栈中元素个数
	void MakeEmpty() { top = -1; }//清空栈内容
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
	T* elements; //存放栈中元素的栈数组
	int top;//栈顶指针
	int maxSize;//栈最大可容纳的元素个数
	void overflowProcess();//栈溢出处理
};

template<class T>
SeqStack<T>::SeqStack(int sz) :top(-1), maxSize(sz)
{//建立一个最大尺寸为sz的空栈
	elements = new T[maxSize];
	assert(elements != nullptr); //条件成立继续执行
}

template<class T>
void SeqStack<T>::Push(T& x)
{
	if (IsFull()) overflowProcess();
	elements[++top] = x; //栈顶指针加1再进栈
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
{//栈溢出处理
	T* newArray = new T[maxSize + stackIncrement];
	if (newArray == NULL)
	{
		cerr << "分配内存失败" << endl;
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


