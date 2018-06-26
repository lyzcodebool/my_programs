#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partation(int *a, int left, int right)
{
    int i = left;
    int j = right;
    while(i < j){
        while(i < right && a[++i] < a[left]);
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
        int middle = partation(a, left, right);
        quicksort(a, 0, middle - 1);
        /* 这里left必须为0,因为下面这个语句left值会改变，容易出错 */
        quicksort(a, middle + 1, right);
    }
}

int main()
{
    int a[] = {2, 4, 3, 1, 0};
    quicksort(a, 0, 5);
    for(int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);

    return 0;
}

