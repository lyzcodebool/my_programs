#include <stdio.h>
#include <stdlib.h>

int number(int n)
{   
    int num = 0;
    while(n)
    {
        n &= (n-1);
        num += 1;;
    }
    return num;
}

int main(void)
{

    int n = number(12);
    printf("%d \n",n);
        

    return 0;
}
