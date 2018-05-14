#include <stdio.h>
#include <stdlib.h>
int in2_1(int n)
{
    int total = 0;
    while(n)
    {
        if((n&1)  == 1)
            total += 1;

        n = n>>1;
    }


    return total;
}

int main(void)
{
    int n = in2_1(9);
    printf("%d\n",n);
}
