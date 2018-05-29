#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str = "abcASJSJJ";
    char *dst = "bc";
    printf("%p  %c\n", dst, *dst);

    while(*dst != '\0'){
        printf("%c\n", *dst);
        dst++;
    }
    /* while((*dst++) != '\0'){ */
    /*     printf("1\n"); */
    /* } */
    printf("*dst = %c\n", *dst);
    printf("dst[0] = %p, %c\n", &dst[0], dst[0]);
    printf("dst[2] = %p\n", &dst[2]);
    printf("%p  %c\n", dst, *dst);
    if(*dst == '\0')
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
