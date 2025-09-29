//
// Created by yangning on 2025/9/27.
//
#pragma once
#include<iostream>

template<class T>
struct BinTreeNode
{
    T data;//数据域
    BinTreeNode<T>* leftChild,*rightChild;
    BinTreeNode():leftChild(nullptr),rightChild(nullptr){}
    BinTreeNode(T x,BinTreeNode<T> *l=nullptr,BinTreeNode<T> *r=nullptr)
        :data(x),leftChild(l),rightChild(r){}
};
template<class T>
class BinaryTree
{
public:
    BinaryTree():root(nullptr){}//构造函数
    BinaryTree(T value):root(nullptr),RefValue(value){}//构造函数
    BinaryTree(BinaryTree<T> &s);//拷贝构造
    ~BinaryTree() {destory(root);} //析构函数
    bool IsEmpty() {return root == nullptr;}//判断二叉树是否为空
    /**
     * @brief 找到父节点
     * @param current 当前树节点
     * @return 父指针
     */
    BinTreeNode<T> *Parent(BinaryTree<T> *current)
    {
        if (root == nullptr||current==root) return NULL;
        else return Parent(root,current);
    }
    /**
     * @brief 得到二叉树的高度
     * @return 返回二叉树的高度
     */
    int Height(){return Height(root);}
    /**
     * 得到二叉树的节点数
     * @return 二叉树的结点数
     */
    int Size(){return Size(root);}
    /**
     * 根得到节点
     * @return 根结点
     */
    BinTreeNode<T> *Root(){return root;}
    /**
     * 修改根
     * @param p 根结点
     */
    void setRoot(BinTreeNode<T> *p){root = p;}
    /**
     * 搜索
     * @param item 值
     * @return 二叉树结点地址
     */
    BinTreeNode<T> *Search(T item){return Search(root,item);}
    /**
     * 插入新元素
     * @param item 值
     * @return
     */
    int Insert(T item){return Insert(root,item);}
protected:
    BinTreeNode<T>* root;//二叉树跟指针
    T RefValue;//数据输入停止标志
    void destory(BinTreeNode<T>* &subTree);//销毁子树
};