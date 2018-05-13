#include <stdio.h>
#include <stdlib.h>

typedef struct json_node{
    int data;
    struct json_node *next;
}*pNode;

void jsonphus_result(int total, int from, int count)
{
    pNode pCur, pre, head;
    head = NULL;
    int i;
    for(i = 0; i < total; ++i){
        pCur = (pNode)malloc(sizeof(pNode));
        pCur->data = i;
        if(NULL == head)
            head = pCur;
        else
            pre->next = pCur;
        pre = pCur;
    }
    pCur->next = head;
    pCur = head;
    //把当前的pCur移动到第一个报数的人的位置
    for(i = 1; i < from; ++i){
        pre =pCur;
        pCur = pCur->next;
    }
    //循环的删除队列节点，每隔count-1个节点刷一个
    while(pCur->next != pCur)
    {
        for(i = 1; i < count; ++i){
            pre = pCur;
            pCur = pCur->next;
        }
        pre->next = pCur->next;
        printf("%d\n", pCur->data);
        free(pCur);
        pCur = pre->next;
    }
    printf("the last one is: %d\n", pCur->data);
}

int main(void)
{
    jsonphus_result(13, 1, 3);

    return 0;
}
