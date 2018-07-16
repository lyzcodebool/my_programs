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
        p = pHead; //保存当前节点
        s = p->m_next;  //s用来保存下一个节点
        p->m_next = NULL; //第一个节点的下一个节点设置为null
        while(s){
            p = s;  //保存当前节点
            s = s->m_next;  //s用来保存下一个节点
            p->m_next = pHead;  //当前节点指向前一个节点
            pHead = p;  //更新当前节点
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

