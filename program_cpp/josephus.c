#include <stdio.h>
#include <stdlib.h>
//约瑟夫环

typedef struct Josephus{
    int data;
    struct Josephus *next;
}*pNode;

void josephus(int total, int from, int count){
    
    //构造约瑟夫环
    pNode head = NULL, pCurr, pre;
    for(int i = 0; i < total; ++i)
    {
        pCurr = (pNode)malloc(sizeof(pNode));
        pCurr->data = i;
        if(head == NULL){
            head = pCurr;
        }else{
            pre->next = pCurr;
        }
        pre = pCurr;
    }
    pCurr->next = head;
    pCurr = head;
    for(int i = 0; i < from; ++i){
        pCurr = pCurr->next;
    }
    while(pCurr->next != head){
        for(int i = 1; i < count; i++){
            pre = pCurr;
            pCurr = pCurr->next;
        }
        pre->next = pCurr->next;
        printf("淘汰: %d\n", pCurr->data);
        free(pCurr);
        pCurr = pre->next; 
    }
        printf("胜者: %d\n", pCurr->data);
}

int main(void)
{


    return 0;
}
