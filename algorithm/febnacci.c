#include <stdio.h>

long long  Fibnacci(unsigned int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 0;
    return Fibnacci(n-1) + Fibnacci(n-2);
}

int main(void)
{

    Fibnacci(100);
    putchar(10);
    
    return 0;
}
