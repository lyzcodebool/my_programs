#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strstr_count(const char *s, const char *child)
{
    char *p = strstr(s, child);
    return p?1+strstr_count(p+1, child):0;
}

int main(void)
{
    int count = 0;
    char *str1 = "abcabcaabbccABCABCnnnnabcmmmabcabcIIIJAHDAABCabckkk";
    char *str2 = "abc";
    

    int n = strstr_count(str1, str2);
    printf("%d\n", n);
    /* int n = strlen(str2); */
    char *p = NULL;
    while((p = strstr(str1, str2)) != NULL)
    {
        printf("%c", *str1);
        count++;
        str1 = p + 1;
    }
        
    printf("count = %d\n", count);

        /* char *p = strstr(str1, str2); */
        /* printf("&p : %p \n", p); */
        /* printf("str1: %p\n", str1); */
        /* if(p != NULL){ */
        /*     count ++; */
        /*     str1 += n; */
        /* } */
        /* else */
        /*     break; */
    return 0;
}
