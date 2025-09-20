#pragma once
#include<iostream>
using namespace std;

//���嵥������
template <class T>
struct LinkNode
{
	T data;//������
	LinkNode<T>* link;//ָ����
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }//��ʼ��ָ���Ա
	LinkNode(const T& item, LinkNode<T>* ptr = NULL)
	{//constֻ�����������Ч��
		data = item;
		link = ptr
	}
};

//��ʽջ�ඨ��
template <class T>
class LinkedStack
{
public:
	LinkedStack() :top(NULL) {}//���캯���ÿ�ջ
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
	{//���ջ��Ԫ�ص����ز���
		os << "ջ��Ԫ�صĸ���Ϊ��" << s.getsize << endl;
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
	LinkNode<T>* top; //ջ��ָ��or��ͷָ��
};

template<class T>
inline void LinkedStack<T>::Push(T x)
{
	LinkNode<T>* s = new LinkNode<T>(x);
	if (s == NULL)
	{
		cerr << "������ѵʧ��" << endl;
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
{//���ɾȥջ�е�Ԫ��ֱ��Ϊ��
	LinkNode<T>* p;
	while (top != NULL)
	{
		p = top;
		top = top->link;
		delete p;
	}
}

