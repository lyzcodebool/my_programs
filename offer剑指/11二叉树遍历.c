#include <stdio.h>

struct BinaryTreeNode{
    int   m_value;
    BinaryTreeNode *LeftNode;
    BinaryTreeNode *RightNode;
};


//中序遍历
void midPrintf(BinaryTreeNode *root)
{
    if(root == NULL)
        return;
    if(root->LeftNode){
        midPrintf(root->LeftNode);
    }
    printf("%d ", root->m_value);
    if(root->RightNode){
        midPrintf(root->RightNode);
    }
    putchar(10);
}

//前序遍历
void perPrintf(BinaryTreeNode *root)
{
    if(root == NULL)
        return;
    printf("%d ", root->m_value);
    if(root->LeftNode){
        perPrintf(root->LeftNode);
    }
    if(root->RightNode){
        perPrintf(root->RightNode);
    }

    putchar(10);
}

//后序遍历
void postPrintf(BinaryTreeNode *root)
{
    if(root == NULL)
        return;
    if(root->LeftNode){
        postPrintf(root->LeftNode);
    }
    if(root->RightNode){
        postPrintf(root->RightNode);
    }
    printf("%d ", root->m_value);

    putchar(10);
}

//栈方法，先循环把节点压入栈中，然后再逐个弹出

int main()
{
    return 0;
}

