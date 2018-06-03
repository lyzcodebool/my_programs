#include <stdio.h>
#include <stdlib.h>

typedef struct NodeList{
    int data;
    struct NodeList *next;
}*pNode;

pNode initHead()
{
    pNode pHead = (pNode)malloc(sizeof(pNode));
    if(pHead == NULL)
        exit(1);

    pNode->data = 0;
}
