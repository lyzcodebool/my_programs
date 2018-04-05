#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int *p;
    int a;
    //char b;
//    char c;
    int b;
    char c;

}point;
int main(void)
{
    
    printf("sizeof(point): %lu\n", sizeof(point));
    int *p = NULL;
    printf("*size:%lu\n", sizeof(p));
    printf("int size: %lu\n", sizeof(int));
    printf("long size: %lu\n", sizeof(long));

    return 0;
}
