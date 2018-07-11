#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int m_nValue;
    ListNode *m_pNext;
};

void AddToTail(ListNode **pHead, int value)
{
    ListNode *pNew = (ListNode *)malloc(sizeof(struct ListNode));
    if(pNew == NULL)
        exit(1);
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if(*pHead == NULL){
        *pHead = pNew;
    }else{
        ListNode *pNode = *pHead;
        while(pNode->m_pNext != NULL)
            pNode = pNode->m_pNext;
        pNode->m_pNext = pNew;
    }
}

int main()
{
    return 0;
}

