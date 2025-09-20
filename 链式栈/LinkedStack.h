#pragma once
#include<iostream>
using namespace std;

//定义单链表结点
template <class T>
struct LinkNode
{
	T data;//数据域
	LinkNode<T>* link;//指针域
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }//初始化指针成员
	LinkNode(const T& item, LinkNode<T>* ptr = NULL)
	{//const只读保护，提高效率
		data = item;
		link = ptr
	}
};

//链式栈类定义
template <class T>
class LinkedStack
{
public:
	LinkedStack() :top(NULL) {}//构造函数置空栈
	~LinkedStack() { makeEmpty(); }
	void Push(T x);
	bool Pop(T& x);
	bool getTop(T& x)const;
	bool IsEmpty()const
	{
		return (top == NULL) ? true : false;
	}
	int getsize()const;
	void makeEmpty();
	friend ostream& operator << (ostream& os, LinkedStack<T>& s)
	{//输出栈中元素的重载操作
		os << "栈中元素的个数为：" << s.getsize << endl;
		LinkNode<T>* p = s.getTop;
		while (p != NULL)
		{
			os << p->data << " ";
			p = p->link;
		}
		os << endl;
		return os;
	}
private:
	LinkNode<T>* top; //栈顶指针or链头指针
};

template<class T>
inline void LinkedStack<T>::Push(T x)
{
	LinkNode<T>* s = new LinkNode<T>(x);
	if (s == NULL)
	{
		cerr << "分配内训失败" << endl;
		exit(1);
	}
	s->link = top;
	top = s;
}

template<class T>
inline bool LinkedStack<T>::Pop(T& x)
{
	if (IsEmpty()) return false;
	LinkNode* p = top;
	top = top->data;
	x = p->data;
	delete p;
	return true;
}

template<class T>
inline bool LinkedStack<T>::getTop(T& x) const
{
	if (IsEmpty()) return false;
	x = top->data;
	return true;
}

template<class T>
inline int LinkedStack<T>::getsize() const
{
	LinkNode* p = top;
	int k = 0;
	while (p!= NULL)
	{
		p = p->link;
		k++;
	}
	return k;
}

template<class T>
inline void LinkedStack<T>::makeEmpty()
{//逐次删去栈中的元素直至为空
	LinkNode<T>* p;
	while (top != NULL)
	{
		p = top;
		top = top->link;
		delete p;
	}
}

