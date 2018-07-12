#include <stdio.h>
/* 迭代法 */
struct ListNode{
    int m_nValue;
    struct ListNode *m_next;
};

ListNode *Reverse(ListNode *pHead)
{
    ListNode *p  = NULL, *s = NULL;
    if(pHead->m_next && p->m_next->m_next){
        p = pHead;
        s = p->m_next;
        p->m_next = NULL;
        while(s){
            p = s;
            s = s->m_next;
            p->m_next = pHead;
            pHead = p;
        }
    }
    return pHead;
}

/* 递归法 */
ListNode *Reserve2(ListNode *pHead)
{
    if(pHead == NULL || pHead->m_next == NULL)
        return pHead;
    ListNode *newNode = Reserve2(pHead->m_next);
    pHead->m_next->m_next = pHead;
    pHead->m_next = NULL;
    
    return newNode;
}

int main()
{
    return 0;
}

