#include <stdio.h>
#include <stdlib.h>

void maintainheap(int *heap, int startPoint, int size)
{
    int maxIdx = startPoint;
    int max = heap[startPoint];
    int leftNode = startPoint<<1|1;
    int rightNode = leftNode + 1;

    if(leftNode < size){
        if(heap[leftNode] < max){
            maxIdx = leftNode;
            max = heap[leftNode];
        }

        if(rightNode < size && heap[rightNode] < max){
            maxIdx = rightNode;
            max = heap[rightNode];
        }

        if(maxIdx != startPoint){
            heap[maxIdx] = heap[startPoint];
            heap[startPoint] = max;
            maintainheap(heap, maxIdx, size);
        }
    }
}

void makeHeap(int *heap, int size)
{
    for(int i = size/2-1; i >= 0; i--)
    {
        maintainheap(heap, i, size);
    }
}

int main(void)
{
    int a[10] = {2, 4, 3, 1, 5, 8, 0, 7, 6, 9};

    makeHeap(a,10);

    for(int i = 0; i < 10; ++i)
    {
        printf("%d ", a[i]);
    }
    putchar(10);
    return 0;
}

