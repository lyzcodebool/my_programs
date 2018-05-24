#include <stdio.h>
#include <stdlib.h>

int main(void)
 {
    int *p;
     {
         int a = 10;

         p = &a;
         printf("%p", &a);

     }

     int *b = (int *)malloc(sizeof(int));
     b = p;
     free(b);
     b = NULL;

     return 0;
 }
                  
