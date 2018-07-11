#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int m_nValue;
    struct ListNode *m_pNext;
};

void RemoveNode(ListNode **pHead, int value)
{
    if(pHead == NULL || *pHead == NULL)
        return;
    ListNode *pToBeDeleted = NULL;
    if((*pHead)->m_nValue == value){
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode *pNode = *pHead;
        while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value){
            pNode = pNode->m_pNext;
            if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value){
                pToBeDeleted = pNode->m_pNext;
                pNode->m_pNext = pNode->m_pNext->m_pNext;
            }
        }
        if(pToBeDeleted != NULL){
            free(pToBeDeleted);
            pToBeDeleted = NULL;
        }
    }
}
int main()
{
    return 0;
}

