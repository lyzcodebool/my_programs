#ifndef _TWO_FORK_TREE_H_
#define _TWO_FORK_TREE_H_

#include <stdlib.h>
#include <stdio.h>
typedef  struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}*BiTree, BiTNode;

//初始化构造一个新的二叉树
BiTree InitBiTree(BiTNode *root){
    BiTree tree = root;
    return tree;
}

//生成节点
BiTNode *MakeNode(int item, BiTNode *lchild, BiTNode *rchild)
{
    BiTNode *pnode = (BiTNode *)malloc(sizeof(BiTNode));
    if(pnode){
        pnode->data = item;
        pnode->lchild = lchild;
        pnode->rchild = rchild;
    }

    return pnode;
}

//释放结点
void FreeNode(BiTNode *pnode){
    if(pnode != NULL){
        free(pnode);
    }
}

//销毁一切二叉树
void DestroyBiTree(BiTree tree){
    BiTNode *pnode = tree;

    if(pnode->lchild != NULL)
        DestroyBiTree(pnode->lchild);
    if(pnode->rchild != NULL)
        DestroyBiTree(pnode->rchild);
    FreeNode(pnode);
}

//判断树是否为空
bool IsEmptyTree(BiTree tree)
{
    if(tree == NULL){
        return 0;
    }else{
        return 1;
    }
}

//返回树的深度
int GetDepth(BiTree tree){
    int l_depth, r_depth, h_depth;
    l_depth = r_depth = h_depth = 0;
    if(tree){
        l_depth = GetDepth(tree->lchild);
        r_depth = GetDepth(tree->rchild);
        h_depth = (l_depth < r_depth)?l_depth:r_depth;
        return h_depth+1;
    }else{
        return 0;
    }
}

//返回根
BiTree GetRoot(BiTree tree){
    return tree;
}

//返回结点值
int Getint(BiTNode *pnode){
    return pnode->data;
}

//设置节点值
void Setint(BiTNode *pnode, int item){
    pnode->data = item;
}

//设置左子树
BiTree SetLChild(BiTree parent, BiTree lchild){
    parent->lchild = lchild;
    return lchild;
}

//设置右子树
BiTree SetRChild(BiTree parent, BiTree rchild){
    parent->rchild = rchild;
    return rchild;
}

//返回左子树
BiTree GetLChild(BiTree tree){
    if(tree){
        return tree->lchild;
    }
    return NULL;
}
BiTree GetRChild(BiTree tree){
    if(tree){
        return tree->rchild;
    }
    return NULL;
}
//插入新子树
BiTree InserChild(BiTree parent, int lr, BiTree child){
    if(parent)
    {
        if(lr == 0 && parent->lchild==NULL){
            parent->lchild = child;
            return child;
        }
        if(lr == 1 && parent->rchild==NULL){
            parent->rchild = child;
            return child;
        }
    }
    else
        return NULL;
    return NULL;
}

#endif
