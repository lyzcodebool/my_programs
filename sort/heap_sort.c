#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maintainHeap(int *heap, int startPoint, int size)
{
    int leftNode = startPoint<<1|1;
    int rightNode = leftNode+1;

    if(leftNode <= size){
        maintainHeap(heap, leftNode, size);
        if(heap[leftNode] < heap[startPoint])
            swap(&heap[leftNode], &heap[startPoint]);
    }

    if(rightNode <= size){
        maintainHeap(heap, rightNode, size);
        if(heap[rightNode] < heap[startPoint])
            swap(&heap[rightNode], &heap[startPoint]);
    }
}

void heap_sort(int *heap, int size)
{
    int len = size - 1;
    while(len){
        maintainHeap(heap, 0, len);
        swap(&heap[0], &heap[len]);
        --len;
    }
}

void detele_heaptop(int *heap, int size)
{
    if(size == 0){
        printf("This heap is empty\n");
        return;
    }
    int len = size-1;
    int child = 1;
    int parent = 0;
    for(parent; (parent<<1|1) < len; parent = child){
        child = parent<<1|1;
        if(child+1 < len){
            if(heap[child] > heap[child + 1])
                child ++;
        }
        if(heap[len] > heap[child]){
            break;
        }else{
            heap[parent] = heap[child];
        }
    }
    heap[parent] = heap[len];
    return;
}

int main(void)
{
    int a[] = {2, 4, 3, 1, 5};

    heap_sort(a, 5);
    for(int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
    return 0;
}
