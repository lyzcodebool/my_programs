#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    printf("%p\n", sbrk(0));
    int *p = (int *)malloc(4444);
    int n = malloc_usable_size(p);
    printf("n = %d\n", n);
    printf("%p\n", sbrk(0));
    free(p);
    
    return 0;
}
