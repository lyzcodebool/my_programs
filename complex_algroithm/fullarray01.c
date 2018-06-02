#include <stdio.h>
#include <stdlib.h>

//测试
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printarr(int *a, int size){
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
    putchar(10);
}
void perm(int *a, int size)
{
    for(int i = 0; i < size; ++i){
        for(int j  = 0; j < size-1; j ++){
            swap(&a[j], &a[j+1]);
            printarr(a, size);
        }
    }
}

int main(void)
{
    int a[4] = {'a', 'b', 'c', 'd'};
    perm(a, 4);
    return 0;
}
