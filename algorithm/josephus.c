#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//链表节点
typedef struct _RingNode{
    int pos; //位置
    struct _RingNode *next;
}RingNode, *RingNodePtr;

//创建约瑟夫环 pHead：链表头指针 count:链表节点个数
void CreateRing(RingNodePtr pHead, int count)
{
    RingNodePtr pCurr = NULL, pPrev = NULL;
    int i = 1;
    pPrev = pHead;
    while(--count > 0){
        pCurr = (RingNodePtr)malloc(sizeof(RingNode));
        i++;
        pCurr->pos = i;
        pPrev->next = pCurr;
        pPrev = pCurr;
    }

    pCurr->next = pHead;
}

void PrintRing(RingNodePtr pHead){
    RingNodePtr pCurr;
    printf("phead = %d\n", pHead->pos);
    pCurr = pHead->next;

    while(pCurr != NULL){
        if(pCurr->pos == 1)
            break;
        printf("%d ", pCurr->pos);
        pCurr = pCurr->next;
    }
}

void KickFromRing(RingNodePtr pHead, int m)
{
    RingNodePtr pCurr, pPrev;
    int i = 1;
    pCurr = pPrev = pHead;
    while(pCurr != NULL){
        if(i == m){
            printf("出局: %d\n", pCurr->pos);
            pPrev->next = pCurr->next;
            free(pCurr);
            pCurr = pPrev->next;
            i = 1;
        }
        pPrev = pCurr;
        pCurr = pCurr->next;
        if(pPrev == pCurr){
            //最后一个
            printf("赢家: %d\n", pCurr->pos);
            free(pCurr);
            break;
        }
        i++;
    }
}

int main(void)
{
    int m = 0, n = 0;
    RingNodePtr pHead = NULL;
    printf("-------------JOSEPHUS RING---------------\n");
    printf("N(person count) = ");
    scanf("%d", &n);
    printf("M(out number) = ");
    scanf("%d", &m);
    if(n <= 0 || m <= 0){
        printf("Input Error\n");
        return 0;
    }

    // 建立链表
    pHead = (RingNodePtr)malloc(sizeof(RingNode));
    pHead->pos = 1;
    pHead->next = NULL;
    CreateRing(pHead, n);
 #ifdef _DEBUG
    PrintRing(pHead);
 #endif

     // 开始出圈
     printf("\nKick Order: ");
     KickFromRing(pHead, m);
     printf("\n");
     return 0;
}
