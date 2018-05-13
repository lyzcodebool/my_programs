#include <stdio.h>
int fun()
{
    static int i = 0;
    for(i = 0; i < 10; ++i)
    {
        return i;
    }
}

int main(void)
{
    int n = 0;
    while(n < 10)
    {
        printf("%d\n", fun());
        n++;
    }
}
