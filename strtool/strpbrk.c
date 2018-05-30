#include <stdio.h>
/*strpbrk()*/
//检测拉开嗯个字符串中首个相同字符的位置。
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char str1[30] = "GET http://baidu.com";
    char str2[30] = " \t";

    char *p = strpbrk(str1, str2);
    if(p == NULL){
        printf("%s\n", p);
        printf("error\n");
    }else{
        printf("%s\n", p);
    }
    *p++ = '\0';
    printf("%s\n", p);

    return 0;
}
