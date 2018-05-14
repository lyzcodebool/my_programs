#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maintainheap(int *heap, int startPoint, int size)
{
    int leftNode = startPoint<<1|1;
    int rightNode = leftNode + 1;

    if(leftNode <= size)
    {
        maintainheap(heap, leftNode, size);
        if(heap[startPoint] > heap[leftNode])
            swap(&heap[leftNode], &heap[startPoint]);
    }
    if(rightNode <= size)
    {
        maintainheap(heap, rightNode, size);
        if(heap[startPoint] > heap[rightNode])
            swap(&heap[rightNode], &heap[startPoint]);
    }
}

void heapSort(int *heap, int size)
{
    int len = size-1;
    while(len){
        maintainheap(heap, 0, len);
        swap(&heap[0], &heap[len]);
        --len;
    }
}

int main(void)
{
    int a[] = {10, 9, 11, 6, 20, 17, 7, 0, 78, 34};
    heapSort(a,10);
    for(int i = 0; i < 10; i ++)
    {
        printf("%d ", a[i]);
    }
    putchar(10);
}
