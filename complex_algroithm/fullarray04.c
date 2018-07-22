#include <stdio.h>
#include <stdlib.h>

void print(int *a, int size)
{
    for(int i = 0; i < size; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
}


void swap(int *a, int *b)
{
    int temp = *a; 
    *a = *b;
    *b = temp;
}

void perm(int *a, int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size-1; ++j){
            swap(&a[j], &a[j+1]);
            print(a, size);
        }
    }
}

int main()
{
    int a[] = {1, 2, 3, 4};
    perm(a, 4);
    return 0;
}

