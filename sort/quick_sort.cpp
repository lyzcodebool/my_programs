#include <iostream>
//快速排序
//不稳定
using namespace std;
int partition_quicksort(int *a, int low, int high)
{
    int i = low;
    int j = high;
    while(i < j)
    {
        while(a[++i] < a[low] && i < high);
        while(a[--j] > a[low]);
        if(i < j)
            std::swap(a[i], a[j]);
    }

    std::swap(a[low], a[j]);
    return j;
}

void quick_sort(int *a, int low, int high)
{
    if(low < high){
        int middle = partition_quicksort(a, low, high);

        quick_sort(a, low, middle-1);
        quick_sort(a, middle+1, high);
    }
}

int main(void)
{
    int a[5] = {2, 4, 1, 3, 1};
    quick_sort(a, 0, 5);
    for(int i = 0; i < 5; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
