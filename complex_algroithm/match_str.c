#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//字符串匹配
enum BOOL{
    FALSE = 0,
    TRUE
};
typedef char bool;
#define false 0
#define true 1

bool  match_str(char *src, char *dst)
{
    int str_len = strlen(dst);
    printf("strlen of dst :%d\n", str_len);
    int count = 0;  //记录从哪匹配上的位置
    int dst_n = 0;
    char *tmp = dst;
    char *str;
    if(src == NULL || dst == NULL)
        return false;
       
    while(*src != '\0'){
        count++;
        str = src;
        while((*str) == (*tmp)){
            dst_n++;
            str++;
            tmp++;
        }
        if(*tmp == '\0')
            break;
        /* if(dst_n == str_len) */
        /*     break; */
        src++;
        tmp = dst;
    }
    if(dst_n != (int)strlen(dst))
        return false;
    printf("count = %d\n", count);
    return true;
}

int main(void)
{
    char *str1 = "IIAJDAKDLL";
    char *str2 = "AJDAK";

    int n = match_str(str1, str2);
    if(n == true)
        printf("finded!\n");
    else
        printf("not find\n");

    return 0;
}
