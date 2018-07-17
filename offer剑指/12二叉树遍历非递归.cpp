#include <iostream>
#include <stack>
using namespace std;

struct BinaryTreeNode{
    int m_vlue;
    struct BinaryTreeNode *lchild;
    struct BinaryTreeNode *rchild;
};

//中序遍历
void midPrintNode(BinaryTreeNode *root)
{
    if(root == NULL)
        return;

    BinaryTreeNode *p = root;
    stack<BinaryTreeNode*> s;

    while(!s.empty() || p)
    {
        if(p){
            s.push(p);
            p = p->lchild;
        }else{
            p = s.top();
            s.pop();
            cout<<p->m_vlue<<" ";
            p = p->rchild;
        }
    }
}

//前序遍历
void perPrintNode(BinaryTreeNode *root)
{
    if(root == NULL)
        return;
    BinaryTreeNode *p = root;
    stack<BinaryTreeNode*> s;
    while(!s.empty() || p)
    {
        if(p){
            cout<<p->m_vlue<<" ";
            s.push(p);
            p = p->lchild;
        }else{
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}


//后序遍历
void postPrintNode(BinaryTreeNode *root)
{
    if(root == NULL)
        return;
    stack<BinaryTreeNode*> s;
    BinaryTreeNode *pCurr, *pLastVisit;
    pCurr = root;
    pLastVisit = NULL;

    while(pCurr){
        s.push(pCurr);
        pCurr = pCurr->lchild;
    }
    while(!s.empty()){
        pCurr = s.top();
        s.pop();
        if(pCurr->rchild == NULL || pCurr->rchild == pLastVisit){
            cout<<pCurr->m_vlue;
            pLastVisit = pCurr;
        }else{
            s.push(pCurr);
            pCurr = pCurr->rchild;
            while(pCurr){
                s.push(pCurr);
                pCurr = pCurr->lchild;
            }
        }

    }

    cout<<endl;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

