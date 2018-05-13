#include <stdio.h>

/* union { */
/*     short n; */
/*     char ch; */
/* }data; */
/* int main(void) */
/* { */
/*     data.n = 0x1234; */
    
/*     if(data.ch == 12){ */
/*         printf("BIg"); */
/*     }else{ */
/*         printf("LITTLE"); */
/*     } */
/*     return 0; */
/* } */


int main(void)
{
    int a = 0x1234;
    char b = *(char *)&a;

    if(b == 0x12){
        printf("big");
    }else{
        printf("LITTLE");
    }
    putchar(10);
    printf("%x   \n", b);

    return 0;
}
