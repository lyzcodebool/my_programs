#include <iostream>
#include<algorithm>    
using namespace std;    
#define LEN 6    
    
int a[]={10,9,11,6,20,17};    
    
void quickSort(int l,int r)    
{    
    if(l>=r)    
        return;    
    int i=l,j=r,x=a[l];//以第一个数为基准    
    while(i<j)    
    {    
        while(i<j && a[j]>=x)//从右向左找第一个小于x的数    
            j--;    
        if(i<j)    
            a[i++]=a[j];    
        while(i<j && a[i]<=x)//从左向右找第一个大于x的数    
            i++;    
        if(i<j)    
            a[j--]=a[i];    
    }     
    a[i]=x;    
    quickSort(l,i-1);    
    quickSort(i+1,r);    
}     
    
int main()    
{    
    quickSort(0,LEN-1);    
    for(int i=0;i<LEN;i++)    
        cout<<a[i]<<" ";    
    cout<<endl;    
    return 0;    
}     
