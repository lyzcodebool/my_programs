#include <stdio.h>
#include <stdlib.h>

typedef struct josephus{
    int data;
    struct josephus *next;
}*pNode;

void josephus(int n, int from, int count)
{
    pNode phead = NULL, pCurr;
    pNode per;

    for(int i = 0; i < n; ++i){
        pCurr = (pNode)malloc(sizeof(pNode));
        if(pCurr == NULL)
            perror("malloc");
        pCurr->data = i;
        if(phead == NULL){
            phead = pCurr;
        }else{
            per->next = pCurr;
        }
        per = pCurr;
    }
    pCurr->next = phead;
    pCurr = phead;

    for(int i = 0; i < from; ++i)
    {
        pCurr = pCurr->next;
    }
    while(pCurr->next != pCurr)
    {
        for(int i = 0; i < count; ++i){
            per = pCurr;
            pCurr = pCurr->next;
        }

        per->next = pCurr->next;
        printf("out %d\n", pCurr->data);
        free(pCurr);
        pCurr = per->next;
    }

    printf("the last is %d\n", pCurr->data);
    return;
}

int main(void)
{
    return 0;
}
