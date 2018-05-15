#include <stdio.h>
#include <stdlib.h>
void maintainheap(int *heap, int startPoint, int size)
{
    int minIdx = startPoint;
    int min = heap[startPoint];
    int leftNode = startPoint*2 + 1;
    int rightNode = leftNode + 1;

    if(leftNode < size){
        if(heap[leftNode] < min){
            minIdx = leftNode;
            min = heap[leftNode];
        }

        if(rightNode < size && heap[rightNode] < min){
            minIdx = rightNode;
            min = heap[rightNode];
        }
        
        if(minIdx != startPoint){
            heap[minIdx] = heap[startPoint];
            heap[startPoint] = min;
            maintainheap(heap, minIdx, size);
        }
    }
}

void makeHeap(int *heap, int size)
{
    for(int i = size/2 - 1; i >= 0; i--){
        maintainheap(heap, i, size);
    }
}

/* int delete_heap_top(int *heap, int size) */
/* { */
/*     if(size == 0){ */
/*         printf("heap empty\n"); */
/*         return 1; */
/*     } */
    
/*     swap(&heap[0], &heap[size]); */
/*     int child = 1; */
/*     for(int parent = 0; 2*parent+1 < szie; parent = child){ */
/*         child = parent<<1|1; */
/*         if(child + 1 < szie){ */
/*             if(heap[child] > heap[child + 1]) */
/*                 child ++; */
/*         } */
/*         if(head[child] > heap[parent]) */
/*             break; */
/*         else */ 
/*             swap(&heap[child], heap[parent]); */
/*     } */
/*     return 0; */
/* } */
int main(void)
{
    int a[] = {2, 4, 3, 1, 5, 7, 9, 11, 10, 90, 12};
    makeHeap(a, 11);
    for(int i = 0; i < 11; ++i)
    {
        printf("%d ", a[i]);
    }

    
    putchar(10);
    return 0;
}
