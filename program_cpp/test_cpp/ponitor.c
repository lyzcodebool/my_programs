#include <stdio.h>

void test(int *a, int *b)
{
    *a = *b;
}


int main()
{
    int a = 1;
    int b = 2;
        
    test(&a, &b);
    printf("a = %d b = %d", a, b);
    return 0;
}

