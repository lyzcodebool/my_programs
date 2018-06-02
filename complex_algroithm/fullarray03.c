#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum{
    FALSE = 0,
    TRUE
}BOOL;

/* void swap(int *pStr, int i, int index) */
/* { */
/*     int tmp = pStr[i]; */
/*     pStr[i] = pStr[index]; */
/*     pStr[index] = tmp; */
/* } */

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//没有去重的全排列
//index表示当前选取第几个数，size表示总大小
/* void Perm(int *pStr, int index, int size) */
/* { */
/*     if(index == size-1){ */
/*         static int a = 1; */
/*         printf("第%d个排列: \n", a++); */
/*         for(int i = 0; i < size; ++i){ */
/*             printf("%d ", pStr[i]); */
/*         } */
/*         putchar(10); */
/*     }else{ */
/*         for(int i = index; i != size; i++){ //第i个数分别与它后面的数交换，得到新排列 */
/*             swap(&pStr[i], &pStr[index]); */
/*             Perm(pStr, index+1, size); */
/*             swap(&pStr[i], &pStr[index]); */
/*         } */
/*     } */
/* } */

/* //去重的递归版本的全排列 */
int IsSwap(int *pStr, int nBegin, int nEnd)
{
    for(int i = nBegin; i != nEnd; ++i)
        if(pStr[i] == pStr[nEnd])
            return 0;
    return 1;
}
void Perm_IsSwap(int *pStr, int index, int size)
{
    if(index == size-1){
        /* static int b = 1; */
        /* printf("第%d个排列: \n", b++); */
        for(int i = 0; i < size; ++i){
            printf("%d ", pStr[i]);
        }
        putchar(10);
    }else{
        for(int i = index; i != size; i++){ //第i个数分别与它后面的数交换，得到新排列
            if(IsSwap(pStr, index, i)){
                swap(&pStr[i], &pStr[index]);
                Perm_IsSwap(pStr, index+1, size);
                swap(&pStr[i], &pStr[index]);
            }
        }
    }
}

int main(void)
{
    int a[3] = {1, 2, 2};
    /* Perm(a, 0, 3); */
    printf("====================\n");
    Perm_IsSwap(a, 0, 3);
}
