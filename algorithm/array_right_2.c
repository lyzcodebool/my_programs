#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void array_right_k(int *a, int n, int m)
{
    int i = n;
    int j = m;
    while(i < j)
    {
        swap(&a[i], &a[j]);
        i++;
        j--;
    }

}

void array_turn(int *a, int n, int k)
{
    array_right_k(a, n-k, n-1);
    array_right_k(a, 0, n-k-1);
    array_right_k(a, 0, n-1);

}
int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    array_turn(a, 5, 2);
    for(int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }

    putchar(10);

    return 0;
}
