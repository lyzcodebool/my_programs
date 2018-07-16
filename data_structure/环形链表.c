#include <stdio.h>
#include <stdlib.h>


struct ListNode{
    int data;
    struct ListNode *next;
};

void huanxingList(int total)
{
    ListNode *pHead = NULL, *pCurr = NULL, *pPer = NULL;
    for(int i = 0; i < total; ++i){
        printf("please input:\n");
        pCurr = (ListNode *)malloc(sizeof(ListNode));
        if(pCurr == NULL){
            printf("malloc error!\n");
            exit(1);
        }
        scanf("%d", &pCurr->data);
        if(pHead == NULL){
            pHead = pCurr;
        }else{
            pPer->next = pCurr; 
        }
        pPer = pCurr;
    }
    pCurr->next = pHead;
    pHead = pCurr;
}


int main()
{
    return 0;
}

