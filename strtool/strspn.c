#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strspn

int main(void)
{
    char *str1 = "GET http://baidu.com HTTP/1.1";
    char *p = str1 + strspn(str1, "GET");
    printf("%lu\n", strspn(str1, "GET"));
    if(!p)
        printf("error");
    else
        printf("$%s\n", p);

    return 0;
}
