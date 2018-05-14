#include <stdio.h>

void array_right_k(int *array, int n, int k)
{
    k %= n;
    while(k)   
    {
        int tmp = array[n-1];
        for(int i = n-1; i > 0; i --){
            array[i] = array[i-1];
        }
        array[0] = tmp;
        k--;
    }
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    array_right_k(a, 5, 2);
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    putchar(10);
    return 0;
}
