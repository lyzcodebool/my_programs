#pragma once
#ifndef _BINARY_SERCH_TREE_H_ 
#define _BINARY_SERCH_TREE_H_
#include <iostream>
using namespace std;

enum Boolean{
    FALSE,
    TRUE
};

template<class Type> 
class Element{
public:
    Type key;
    //添加更多的数据
};

template<class Type> class BST; //前置声明
template<class Type> 
class BstNode{
    friend class BST<Type>; //因为需要访问私有的数据成员

private:
    Element<Type> data;
    BstNode* leftNode;
    BstNode* rightNode;
    void display(int i);
};
template<class Type> 
class BST{
public:
    BST(BstNode<Type>*init = 0){
        root = init;
    }
    Boolean Insert(const Element<Type> &x);
    BstNode<Type> *Serch(const Element<Type> &x);
    BstNode<Type> *Serch(BstNode<Type> *, const Element<Type> &x);
    BstNode<Type> *IterSerch(const Element<Type> &x);
    void display(){
        std::cout<<std::endl;
        if(root)
            root->display(1);
        else
            std::cout<<"empty tree"<<std::endl;
        
    }
private:
    BstNode<Type> *root;
};

template <class Type>
void BstNode<Type>::display(int i)
{
    std::cout<<"Position:"<<i<<"  key:"<<data.key<<std::endl;
    if(leftNode) leftNode->display(2*i);
    if(rightNode) rightNode->display(2*i + 1);

}
template <class Type>
Boolean BST<Type>::Insert(const Element<Type> &x)
{
    BstNode<Type> *p = root;
    BstNode<Type> *q = 0; //q指向p的父节点
    
    //insert之前要先查找
    while(p){
        q = p;
        if(x.key == p->data.key)
            return FALSE; //发生重复
        if(x.key < p->data.key){
            p = p->leftNode;
        }
        if(x.key > p->data.key){
            p = p->rightNode;
        }
    }
    //找到的位置就是q
    p = new BstNode<Type>;
    p->leftNode = p->rightNode = 0;
    p->data = x;
    if(!root) //如果树没有根
        root = p;
    else if(x.key < q->data.key)
        q->leftNode = p;
    else
        q->rightNode = p;

    return TRUE;
}

template <class Type>
BstNode<Type> *BST<Type>::Serch(const Element<Type> &x)
{
    Serch(root, x);
}

template <class Type>
BstNode<Type> *BST<Type>::Serch(BstNode<Type> *b, const Element<Type> &x)
{
    if(!b) return 0;
    if(x.key == b->data.key) return b;
    else if(x.key < b->data.key) return Serch(b->leftNode, x);
    else return Serch(b->rightNode, x);
}
template <class Type>
BstNode<Type> *BST<Type>::IterSerch(const Element<Type> &x)
{
    for(BstNode<Type> *t = root; t; ){
        if(x.key == t->data.key)
            return t;
        if(x.key < t->data.key)
            t = t->leftNode;
        if(x.key > t->data.key)
            t = t->rightNode;
    }
    return 0;
}
#endif
