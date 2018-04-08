#include <stdio.h>
int main()
{

    const int a = 10;
    int *p = (int *)&a;
    *p = 10;
    printf("%d   %d\n", *p, a);

    return 0;
}
