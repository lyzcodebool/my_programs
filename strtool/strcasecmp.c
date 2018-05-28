#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *str1 = "http://baidu.com";
    char *str2 = "http://baidu.com";

    if(strcasecmp(str1, str2) == 0)
    {
        printf("==");
    }
    putchar (10);

    return 0;
}
