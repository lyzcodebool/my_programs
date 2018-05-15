#include <iostream>
//堆排序
//非稳定排序算法
//时间复杂度NlgN

using namespace std;

void maintainHeap(int *heap, int startPoint, int size)
{
    int leftNode = startPoint<<1|1;
    int rightNode = leftNode + 1;

    if(leftNode <= size){
        maintainHeap(heap, leftNode, size);
        if(heap[leftNode] < heap[startPoint])
            swap(heap[leftNode], heap[startPoint]);
    }
    if(rightNode <= size){
        maintainHeap(heap, rightNode, size);
        if(heap[rightNode] < heap[startPoint])
            swap(heap[rightNode], heap[startPoint]);
    }
}

void heapSort(int *heap, int size)
{
    int len = size-1;
    while(len){
        maintainHeap(heap, 0, len);
        swap(heap[0], heap[len]);
        --len;
    }
}

int main(void)
{
    int a[] = {4, 6, 2, 1, 3, 6, 7, 0, 45, 23};
    heapSort(a, 10);
    for(int i = 0; i < 10; ++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

