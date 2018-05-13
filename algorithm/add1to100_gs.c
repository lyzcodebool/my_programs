#include <stdio.h>
int return_sum_gs(int n)
{
    int sum = 0;
    if((n & 1) == 0)
        sum = (1+n)*(n/2);
    else 
        sum = (1+n)*(n/2) + (n/2+1);
    return sum;
}

int main(void)
{
    int sum1 = return_sum_gs(100);
    int sum2 = return_sum_gs(101);
    printf("sum1 = %d  sum2 = %d\n", sum1, sum2);
    return 0;
}
