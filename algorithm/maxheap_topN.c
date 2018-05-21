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

int detele_heaptop(int *heap, int size)
{
    if(size == 0)
    {
        printf("This heap is empty\n");
        return 1;
    }

    int len = size-1;
    int child = 1;
    int parent  = 0;

    for(parent = 0; (parent<<1|1) < len; parent = child)
    {
        child = parent<<1|1;
        if(child + 1 < len){
            if(heap[child] >  heap[child + 1])
                child ++;
        }
        if(heap[len] < heap[child])
            break;
        else 
            heap[parent] = heap[len];
    }
    heap[parent] = heap[child];
    return 0;
}

void topk_bymaxheap(int *heap, int size, int k)
{
    heapSort(heap, k);
    for(int i = k; i < size; ++i){
        if(heap[i] > heap[0]){
            heap[0] = heap[i];
            heapSort(heap, k);
        }
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
    detele_heaptop(a, 10);
    for(int i = 0; i < 9; i ++)
    {
        printf("%d ",a[i]);
    }
    putchar(10);

    topk_bymaxheap(a, 10, 3);
    for(int i = 0; i < 3; i ++)
    {
        printf("%d ", a[i]);
    }
    putchar(10);
}
