#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = NULL;
    printf("*size:%lu\n", sizeof(p));
    printf("int size: %lu\n", sizeof(int));
    printf("long size: %lu\n", sizeof(long));

    return 0;
}
