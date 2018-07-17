#include <stdio.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}*pNode;

ListNode *daozhiList(pNode pHead)
{
    if(pHead->next == NULL || pHead == NULL)
        return pHead;

    pNode p  = NULL, s = NULL;
    if(pHead->next && pHead->next->next){
        p = pHead;
        s = p->next;
        p->next = NULL;
        while(s){
            p = s;
            s = s->next;
            p->next = pHead;
            pHead = p;
        }
    }
    return pHead;
}

ListNode *xunhuanList(pNode pHead){
    if(pHead == NULL || pHead->next == NULL)
        return pHead;

    pNode newNode = xunhuanList(pHead->next);
    pHead->next->next = pHead;
    pHead->next = NULL;

    return newNode;
}


int main()
{
    return 0;
}

