#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int m_nValue;
    struct ListNode *m_pNext;
}*pNode;

void josephus(int n, int from, int count)
{
    if(n < 0 || from > n || count > n)
        return;

    pNode pHead = NULL, pCurr, pPer = NULL;
    for(int i = 0; i < n; ++i){
        pCurr = (pNode)malloc(sizeof(pNode));
        if(pCurr == NULL){
            printf("malloc error\n");
            exit(1);
        }
        pCurr->m_nValue = i;
        if(pHead == NULL){
            pHead = pCurr;
        }else{
            pPer->m_pNext = pCurr;
        }
        pPer = pCurr;
    }
    pCurr->m_pNext = pHead;
    pCurr = pHead;

    for(int i = 0; i < from; ++i){
        pCurr = pCurr->m_pNext;
    }

    while(pCurr->m_pNext != pCurr){
        for(int i = 0; i < count; ++i){
            pPer = pCurr;
            pCurr = pCurr->m_pNext;
        }
        pPer->m_pNext = pCurr->m_pNext;
        printf("淘汰了%d\n", pCurr->m_nValue);
        free(pCurr);
        pCurr = pPer->m_pNext;
    }

    printf("%d 胜利啦\n", pCurr->m_nValue);
    return;
}

int main()
{
    josephus(13, 0, 5);
    return 0;
}

