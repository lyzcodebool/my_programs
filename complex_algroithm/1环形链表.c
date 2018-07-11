#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}*pNode;

void AnnulusList(int n)
{
    if(n < 0)
        return;
    pNode pCurr, pHead = NULL, pPer = NULL;
    for(int i = 0; i < n; ++i){
        pCurr = (pNode)malloc(sizeof(pNode));
        if(pCurr == NULL){
            printf("malloc error\n");
        }
        printf("输入节点数值:\n");
        scanf("%d", &pCurr->data);
        getchar();
        if(pHead == NULL){
            pHead = pCurr;
        }else{
            pPer->next = pCurr;
        }
        pPer = pCurr;
    }
    pCurr->next = pHead;
    pCurr = pHead;

    while(pCurr->next != NULL){
        printf("%d ->", pCurr->data);
        putchar(10);
        pCurr = pCurr->next;
    }

}

int main()
{
    AnnulusList(10);

    printf("Hello world\n");
    return 0;
}

