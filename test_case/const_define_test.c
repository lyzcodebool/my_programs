#include <stdio.h>

int main(void)
{
    const int test = 10;

    int *p = (int *)&test;
    *p = 20;

    printf("%d--%d\n", test, *p);

    int const *q = (int *)&test;
    //*q = 30;

    int b  = 10;
    int *const m = (int *)&test;
    q = &b;
    //m = &b;
    *m = b;
}
