#pragma once

#ifndef  _BINARY_TREE_H_
#define  _BINARY_TREE_H_

#include <iostream>
#include <queue>

template<class T>class BinaryTree;
template<class T>
class TreeNode{
    public:
        TreeNode(){
            leftChild = nullptr;
            rightChild = nullptr;
        }
        T data;
        TreeNode<T> *leftChild;
        TreeNode<T> *rightChild;

};

template<class T>
class BinaryTree{
    public:
        //二叉树进行的操作
        void InOrder();
        void InOrder(TreeNode<T> *currentNode);//中序遍历
        void PreOrder();//前序遍历
        void PreOrder(TreeNode<T> *currentNode);//前序遍历
        void PostOrder();//后序遍历
        void PostOrder(TreeNode<T> *currentNode);
        void LevelOrder();//层次遍历
        void Visit(TreeNode<T> *currentNode);
    private:
        TreeNode<T> *root;
};

template<class T>
void BinaryTree<T>::Visit(TreeNode<T> *currentNode)
{
    std::cout<<currentNode->data<<std::endl;
}

template<class T>
void BinaryTree<T>::InOrder()
{
    InOrder(root);
}

template<class T>
void BinaryTree<T>::InOrder(TreeNode<T> *currentNode)//中序遍历
{
    std::cout<<"中序遍历:"<<std::endl;
    if(currentNode){
        InOrder(currentNode->leftChild);
        Visit(currentNode);
        InOrder(currentNode->rightChild);
    }
}

template<class T>
void BinaryTree<T>::PreOrder()
{
    PosetOrder(root);
}

template<class T>
void BinaryTree<T>::PreOrder(TreeNode<T> *currentNode)
{
    if(currentNode)
    {
        Visit(currentNode);
        PosetOrder(currentNode->leftChild);
        PosetOrder(currentNode->rightChild);
    }
}

template<class T>
void BinaryTree<T>::PostOrder()
{
    PosetOrder(root);
}

template<class T>
void BinaryTree<T>::PostOrder(TreeNode<T> *currentNode)
{
    if(currentNode)
    {
        PosetOrder(currentNode->leftChild);
        PosetOrder(currentNode->rightChild);
        Visit(currentNode);
    }
}

template<class T>
void BinaryTree<T>::LevelOrder()
{
    std::queue<TreeNode<T> *> q;
    TreeNode<T> *currentNode = root;
    while(currentNode){
        Visit(currentNode);
        if(currentNode->leftChild)
            q.push(currentNode->leftChild);
        if(currentNode->rightChild)
            q.push(currentNode->rightChild);
        if(q.empty())
            return;
        currentNode = q.front();
        q.pop();
    }
}

#endif
