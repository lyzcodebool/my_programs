#include <stdio.h>
#include <stdlib.h>

int a[] = {1, 3, 2, 6, 4, 7};
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void QuickSort(int left,  int right)
{
    if(left >= right)
        return;
    int i = left, j = right;
    int x = a[left];
    while(i < j)
    {
        while(i < j && a[j] <= x)
            j--;
        if(i < j)
            a[i++] = a[j];
        while(i < j && a[i] >= x)
            i++;
        if(i < j)
            a[j--] = a[i];
    }
    a[i] = x;
    QuickSort(left, i-1);
    QuickSort(i+1, right);
}

int main(void)
{
    QuickSort(0, 5);
    for(int i = 0; i < 6; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
    return 0;
}
