#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//随机打乱一个数组
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rand_array(int *a, int size)
{   
    srand((unsigned) time(NULL));
    for(int i = 0; i < size; ++i)
    {
        int index = rand()%(size-i)+i;
        printf("i = %d  rand = %d\n", i, index);
        swap(&a[i], &a[index]);
    }
}

int main(void)
{
    int a[] = {2, 3, 5, 4, 1, 2};
    for(int i = 0 ; i < 6; ++i)
    {
        printf("%d ", a[i]);
    }
    putchar(10);

    rand_array(a, 6);
    for(int i = 0 ; i < 6; ++i)
    {
        printf("%d ", a[i]);
    }
    putchar(10);

    return 0;
}
