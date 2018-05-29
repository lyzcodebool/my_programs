#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int value;
    struct Link *m_next;
}*pNode;

//带头节点的
pNode initLink()
{
    pNode pHead = NULL;
    pHead = (pNode )malloc(sizeof(pNode));
    pHead->m_next = NULL;
    return pHead;
}

pNode InsertNode(pNode pHead, int value)
{
    pNode pCurr = pHead;
    pNode pNew = (pNode)malloc(sizeof(pNode));
    if(pNew == NULL)
        exit(1);
    pNew->m_next = NULL;
    pNew->value = value;
    if(pHead == NULL)
        pHead->m_next = pNew;
    else{
            while(pCurr->m_next){
                pCurr = pCurr->m_next;
            }
            pCurr->m_next = pNew;
        }
    return pHead;
}

//迭代法链表倒置
pNode reverseLink(pNode pHead)  //针对不带头节点
{
    pNode pCur = pHead->m_next;
    pHead->m_next = NULL;
    pNode ptemp = NULL;
    pNode ptr = NULL;
    while(pCur){
        ptr = pCur->m_next;
        pCur->m_next = ptemp;
        ptemp = pCur;
        pCur = ptr;
    }
    pHead->m_next = ptemp;

    return pHead;
}

//递归方法倒置
pNode reverseLinkByRecursion(pNode pHead)
{
    if(pHead == NULL || pHead->m_next == NULL){
        return pHead;
    }
    pNode newNode = reverseLinkByRecursion(pHead->m_next);
    pHead->m_next->m_next = pHead;
    pHead->m_next = NULL;

    return newNode;
}

void printNode(pNode pHead)
{
    pNode pCurr = pHead;
    printf("%d->", pHead->value);
    while(pCurr->m_next){
        printf("%d ->", pCurr->m_next->value);
        pCurr = pCurr->m_next;
    }
    printf("NULL\n");
}

int main(void)
{
    pNode pHead = initLink();
    for(int i = 0; i < 5; ++i){
        InsertNode(pHead, i);
    }
    printNode(pHead);
    pHead = reverseLink(pHead);
    printNode(pHead);
    pHead = reverseLinkByRecursion(pHead);
    printNode(pHead);
    return 0;
}
