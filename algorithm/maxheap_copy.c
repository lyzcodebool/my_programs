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
    return 0;    
}     
