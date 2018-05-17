#include <stdio.h>
#include <stdlib.h>

/* middle = 4 */
/* 4 3 2 5 1 */
/* middle = 0 */
/* 4 3 2 5 1 */
/* middle = 1 */
/* 4 3 2 5 1 */
/* middle = 2 */
/* 4 3 2 5 1 */
/* 4 3 2 5 1 */

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int partition_quick(int *a, int low, int high)
{
    int i = low;
    int j = high;

    while(i < j)
    {
        while(a[++i] < a[low] && i < high);
        while(a[--j] > a[low]);
        if(i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[low], &a[j]);

    return j;
}

void quickSort(int *a, int low, int high)
{
    if(low < high){
        int middle = partition_quick(a, low, high);
        printf("middle = %d\n", middle);
    for(int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
        quickSort(a, low, middle-1);
        quickSort(a, middle+1, high);
    }
}

int main(void)
{
    int a[] = {1, 3, 2, 5,  4};
    
    quickSort(a, 0, 5);
    for(int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
}
