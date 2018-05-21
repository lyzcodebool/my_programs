#include <stdio.h>
#include <stdlib.h>

typedef struct josephus{
    int             data;
    struct josephus *next;
}*pNode;

void josephus_ret(int total, int from, int count)
{
    pNode pHead = NULL;
    pNode pCurr, pPer;

    for(int i = 0; i < total; ++i){
        pCurr = (pNode)malloc(sizeof(pNode));
        if(pCurr == NULL){
            printf("malloc errori\n");
            exit(1);
        }
        pCurr->data = i;
        if(NULL == pHead)
            pHead = pCurr;
        else{
            pPer->next = pCurr;
        }
        pPer = pCurr;
    }
    pCurr->next = pHead;
    pCurr = pHead;
    
    //从from开始
    for(int i = 0; i < from; ++i){
        pCurr = pCurr->next;
    }

    //淘汰开始,按照间隔COUnt
    while(pCurr->next != pCurr)
    {
        for(int i = 0; i < count; ++i){
            pPer = pCurr;
            pCurr = pCurr->next;
        }
        pPer->next = pCurr->next;
        printf("%d 被淘汰了\n", pCurr->data);
        free(pCurr);

        pCurr = pPer->next;
    }
    printf("%d 获胜\n", pCurr->data);
}

int main(void)
{
    josephus_ret(13, 0, 3);


    return 0;
}
