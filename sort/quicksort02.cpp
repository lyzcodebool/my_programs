#include <iostream>

using namespace std;


int partition_sort(int *a, int low, int high)
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

    std::swap(a[j], a[low]);
    return j;
}


void quicksort(int *a, int low, int high)
{
    if(low < high)
    {
        int middle = partition_sort(a, low, high);
        quicksort(a, 0, middle-1);
        quicksort(a, middle+1, high);
    }
}

int main(void)
{
    int a[] = {1, 2 ,5, 5, 3, 1};
    quicksort(a, 0, 6);
    for(int i = 0; i < 6; ++i)
    {
        cout<<a[i]<<endl;
    }
    cout<<endl;
   
}
