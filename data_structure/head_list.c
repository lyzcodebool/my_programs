#include <stdio.h>
#include <stdlib.h>

typedef struct NodeList{
    int data;
    struct NodeList *next;
}Node;

//初始化头节点的单链表
void InitialList(Node  **pHead)
{
    *pHead = (Node *)malloc(sizeof(Node));
    if(*pHead == NULL)
    {
        printf("error\n");
        exit(1);
    }
    else
        (*pHead)->next = NULL;
}

//尾插法插入数据
void creatList(Node *pHead, int value)
{
    Node *pCurr = pHead;
    Node *pNew = (Node*)malloc(sizeof(Node));
    if(pNew == NULL)
        exit(1);
    pNew->data = value;
    pNew->next = NULL;

    if(pHead == NULL){
        pHead->next = pNew;
    }else{
        while(pCurr->next){
            pCurr = pCurr->next;
        }
        pCurr->next = pNew;
    }
}

void printList(Node *pHead)
{
    Node *pCurr = pHead->next;
    printf("%d->", pHead->data);
    while(pCurr){
        printf("%d->", pCurr->data);
        pCurr = pCurr->next;
    }
    putchar(10);
}

Node *reverseList(Node *pHead)
{
    if(pHead == NULL || pHead->next == NULL)
        return pHead;
    Node *newNode = reverseList(pHead->next);
    pHead->next->next = pHead;
    pHead->next = NULL;

    return newNode;
}

int main(void)
{
    Node *pHead = NULL;
    InitialList(&pHead);
    for(int i = 0; i < 5; ++i)
    {
        creatList(pHead, i);
    }
    printList(pHead);

    pHead = reverseList(pHead);
    printList(pHead);
}

