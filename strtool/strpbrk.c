#include <stdio.h>
/*strpbrk()*/
//检测拉开嗯个字符串中首个相同字符的位置。

#include<stdlib.h>
#include<string.h>

int main(void)
{
    char *str1 = "http://baidu.com";
    char *str2 = "baidu";

    char *p = strpbrk(str1, str2);
    if(p){
        printf("%s\n", p);
    }else{
        printf("error\n");
    }

    return 0;
}
