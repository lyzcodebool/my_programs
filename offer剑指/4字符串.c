#include <stdio.h>

/* 字符串注意不要内存越界，最后有个'\0' */

int main()
{
    char str1[] = "hello world";
    char str2[] = "hello world";
    if(str1 == str2)                       //数组比较总是不想等的 
        printf("str1 == str2\n");
    else
        printf("str1 != str2\n");

    char *str3 = "hello world";
    char *str4 = "hello world";
    if(str3 == str4)
        printf("str3 == str4\n");
    else 
        printf("str3 != str4\n");

    return 0;
}

