#include <stdio.h>

int return_sum(int n)
{
    int sum = 0;
    int i = 1;
    while(i <= n){
        sum += i;
        ++i;
    }
    return sum;
}

int main(void)
{
    int n = return_sum(100);
    printf("add 1 to 100 sum is: %d\n", n);

    return 0;
}
