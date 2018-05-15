#include<iostream>    
#include<algorithm>    
using namespace std;    
#define LEN 6    
    
int a[]={10,9,11,6,20,17};    
    
//以大根堆为例     
void buildHeap(int id, int maxid)    
{    
    int left=id<<1|1;    
    int right=left+1;    
    if(left<=maxid)    
    {    
        buildHeap(left, maxid);    
        if(a[id]<a[left])    
            swap(a[id],a[left]);    
    }    
    if(right<=maxid)    
    {    
        buildHeap(right, maxid);    
        if(a[id]<a[right])    
            swap(a[id],a[right]);    
    }    
        
}     

int detele_top(int *heap, int size)
{
    if(size == 0)
    {
        cout<<"empty"<<endl;
        return 1;
    }

    int child = 1;
    int parent;
    int len = size - 1;
    for(parent = 0; (parent<<1|1) < len; parent = child)
    {
        child = parent<<1|1;
        if(child + 1 < len)
        {
            if(heap[child] > heap[child+ 1])
                child ++;
        }

        if(heap[size] > heap[child])
            break;
        else
            heap[parent] = heap[child];
    }
    heap[parent] = heap[len];
    return 0;
}

void heapSort()    
{    
    int len=LEN-1;    
    while(len)    
    {    
        buildHeap(0,len);    
        swap(a[0],a[len]);    
        --len;    
    }    
}    
    
int main()    
{    
    heapSort();    
    for(int i=0;i<LEN;i++)    
        cout<<a[i]<<" ";    
    cout<<endl;    
    detele_top(a,LEN );
    for(int i=0;i<LEN;i++)    
        cout<<a[i]<<" ";    
    cout<<endl;    
    return 0;    
}     
