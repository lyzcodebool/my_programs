#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void maintainHeap(int *heap, int startPoint, int size)
{
    int leftNode = startPoint<<1|1;
    int rightNode = leftNode+1;

    if(leftNode <= size)
    {
        maintainHeap(heap, leftNode, size);
        if(heap[leftNode] < heap[startPoint])
            swap(&heap[leftNode], &heap[startPoint]);
    }
    if(rightNode <= size)
    {
        maintainHeap(heap, rightNode, size);
        if(heap[rightNode] < heap[startPoint])
            swap(&heap[rightNode], &heap[startPoint]);
    }
}

void heapSort(int *heap, int size)
{
    int len = size-1;
    while(len){
        maintainHeap(heap, 0, len);
        swap(&heap[0], &heap[len]);
        --len;
    }
}

int main(void)
{
    int a[] = {2, 3, 1, 5, 4};

    heapSort(a, 5);
    for(int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }

    putchar(10);
}
