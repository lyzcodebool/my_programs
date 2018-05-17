#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition_sort(int *a, int low, int size)
{
    int i = low;
    int j = size;

    while(i < j){
        while(a[++i] < a[low] && i < size);
        while(a[--j] > a[low]);
        if(i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[j], &a[low]);
    return j;
}

void quick_sort(int *a, int low, int high){
    if(low < high){
        int middle = partition_sort(a, low, high);
        quick_sort(a, 0, middle-1);
        quick_sort(a, middle+1, high);
    }
}

int main(void)
{
    int a[] = {2, 3, 1, 5, 4};

    quick_sort(a, 0, 5);
    for(int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
}
