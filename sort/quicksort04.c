#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *a, int left, int right)
{
    int i = left;
    int j = right;
    while(i < j){
        while(i < right &&  a[++i] < a[left]);
        while(a[--j] > a[left]);
        if(i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[j], &a[left]);
    return j;
}

void quicksort(int *a, int left, int right)
{
    if(left < right){
        int middle = partition(a, left, right);
        quicksort(a, left, middle-1);
        quicksort(a, middle+1, right);
    }
}
int main()
{
    int a[5] = {2, 1, 4, 3 , 5};
    quicksort(a, 0, 4);
    for(int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
    return 0;
}

