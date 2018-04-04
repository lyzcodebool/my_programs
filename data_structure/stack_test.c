#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERR_EXIT(m)\
do{\
    perror("m");\
    exit(1);\
}while(0)

typedef char bool;
#define true 1
#define false 0

typedef int DataType;

typedef struct Node{
    DataType value;
    struct Node *next;
}node, *pnode;

typedef struct StackList{
    DataType size;
    node *bottom;//栈底
    node *top;//栈顶
}StackList;

//栈的初始化
bool StackInit(StackList *s)
{
    s = (StackList *)malloc(sizeof(StackList));
    if(s == NULL){
        return false;
    }else{
        s->size = 0;
        s->bottom = s->top;
        s->top->next = NULL;
        return true;
    }
}

//进栈操作
bool PushStackList(StackList *s, DataType data)
{
    pnode pnew = (pnode)malloc(sizeof(node));
    if(pnew == NULL)
        return false;
        ERR_EXIT("malloc push");
    pnew->value = data;
    pnew->next = s->top;
    s->top = pnew;

    return true;
}

//出栈操作,返回出栈节点的值
bool PopStackList(StackList *s)
{
    int return_val;
    if(s->top){
        return_val = s->top->value;
        pnode ptmp = s->top;
        s->top = s->top->next;
        free(ptmp);
        return return_val;
    }else{
        printf("empty!\n");
    }
}

//打印栈元素
void Print(StackList *s)
{
    if(!s->top){
        printf("栈空\n");
    }else{
        pnode pnew = s->top;
        while(pnew){
            printf("%d ", pnew->value);
            pnew = pnew->next;
    }
        printf("\n");
    }
}
int main(void)
{
    StackList p;
    StackInit(&p);
    PushStackList(&p, 10);
    Print(&p);


    return 0;
}
