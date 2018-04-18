#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{

    int data;
    struct ListNode *next;
} *pNode;

//不带头节点;
/* pNode InitList(pNode head, int newVal) */
/* { */
/*     pNode newNode = (pNode)malloc(sizeof(pNode)); */
/*     newNode->data = newVal; */
/*     newNode->next = NULL; */
/*     if(head == NULL){ */
/*         head = newNode; */
/*         newNode->next = NULL; */
/*     }else{ */
/*         newNode->next = head->next; */
/*         head->next = newNode; */
/*         head = newNode; */
/*     } */

/*     return head; */
/* } */
pNode InitList()
{
    pNode head;
    head = (pNode)malloc(sizeof(pNode));
    head->data = 0;

    head->next = NULL;

    return  head;
}


void InsertList(pNode head, int newVal)
{
    pNode newNode = (pNode)malloc(sizeof(pNode));

    newNode->data = newVal;


    newNode->next = head;
    head = newNode;

}

//反转链表----迭代实现
pNode TailToHead(pNode head)
{
    if(head == NULL || head->next == NULL)
            return  head;
    pNode reserveNode = NULL;
    pNode p = head;
    while(p != NULL){
        pNode q = p;
        q->next = reserveNode;
        reserveNode = q;
        p = p->next;
    }

    return  reserveNode;

}

//反转链表---递归实现
pNode ReverseList(pNode head)
{
    if(head == NULL || head->next == NULL)
            return head;

    pNode newNode = ReverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newNode;
}


void PrintList(pNode head)
{
    pNode p = head;

    while(p != NULL){
        printf("%d->", p->data);
        p = p->next;
    }

    putchar(10);
}


int main(void)
{
    int n= 5;
    pNode head = InitList();
    for(int i = 0; i < n; ++i){
        InsertList(head, i);
    }
    
   PrintList(head);

    return 0;
}
