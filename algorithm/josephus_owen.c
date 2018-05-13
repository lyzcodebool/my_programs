#include <stdio.h>
#include <stdlib.h>

typedef struct josn{
    int data;
    struct josn *next;
}*pNode;

void josnphus(int total, int m, int n)
{
    if(total == 0 || n == 0)
        return;
    pNode head, pCur, pre;

    int i;
    for(i = 0; i < total; ++i){
        pCur = (pNode)malloc(sizeof(pNode));
        if(pCur == NULL)
            exit(1);
        pCur->data = i;
        if(NULL == head)
            head = pCur;
        else 
            pre->next = pCur;
        pre = pCur;
    }
    pCur->next = head;
    pCur = head;
    
    for(i = 1; i < m; ++i){
        pCur = pCur->next;
    }

    while(pCur->next != pCur){
        for(i = 1; i < n; ++i){
            pre = pCur;
            pCur = pCur->next;
        }
        pre->next = pCur->next;
        printf("淘汰：%d\n", pCur->data);
        free(pCur);
        pCur = pre->next;
    }
    printf("获胜者: %d\n", pCur->data);
}
int main(void)
{
    josnphus(13, 1, 3);

    return 0;
}
