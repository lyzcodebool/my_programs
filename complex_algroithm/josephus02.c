#include <stdio.h>
#include <stdlib.h>

typedef struct josephus{
    int data;
    struct josephus *next;
}*pNode;

void josephus_ret(int total , int from, int count)
{
    pNode pHead = NULL;
    pNode pCurr, pPer;
    for(int i = 0; i < total; ++i){
        pCurr = (pNode )malloc(sizeof(pNode));
        if(pCurr == NULL){
            printf("malloc error!\n");
            exit(1);
        }
        pCurr->data = i;
        if(pHead == NULL)
            pHead = pCurr;
        else{
            pPer->next = pCurr;
        }
        pPer = pCurr;
    }
    pCurr->next = pHead;
    pCurr = pHead;

    for(int i = 0; i < from; ++i){
        pCurr = pCurr->next;
    }
    while(pCurr->next != pCurr){
        for(int i = 0; i < count; ++i){
            pPer = pCurr;
            pCurr = pCurr->next;
        }
        pPer->next = pCurr->next;
        printf("淘汰了%d\n", pCurr->data);
        free(pCurr);
        pCurr = pPer->next;
    }
    printf("%d获胜\n", pCurr->data);
}

int main()
{
    josephus_ret(13, 0, 3);
    return 0;
}

