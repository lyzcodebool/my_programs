#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//在源字符串中找到字串
//非递归方法
//
//这个问题要注意找到一个字串之后不是从找到的字串尾部重新找，而是在找到
//该字串的首地址的下一位开始
int littlestr_num(const char *src, const char *dst)
{
    int count = 0;
    int src_len = strlen(src);
    int dst_len = strlen(dst);


    if(src_len <= dst_len)
        return count;

    for(int i= 0; i < src_len; ++i)
    {
        if(*(src+i) == *dst){
            int j = 0;
            for(; i < dst_len; ++j){
                if(*(src+i+j) != *(dst + j))
                    break;
            }
            if(j == dst_len){
                count ++;
            }
        }
    }

    return count;
}

//递归方法
int strstr_count(const char *src, const char *dst)
{
    char *p = strstr(src, dst);
    return p? 1+strstr_count(p+1, dst):0;
}

//strncmp
int strncmp_count(const char *src, const char *dst)
{
    int cnt = 0;
    for(int cmplen = strlen(dst); *src != 0; src++)
    {
        if(strncmp(src, dst, cmplen) == 0){
            cnt++;
        }
    }
    return cnt;
}
int main(void)
{


    return 0;
}
/*
extern char *strstr(char *str1, const char *str2);
语法：
strstr(str1,str2)
str1: 被查找目标　string expression to search.
str2: 要查找对象　The string expression to find.
返回值：若str2是str1的子串，则返回str2在str1的首次出现的地址；如果str2不是str1的子串，则返回NULL。
例子：
char str[]="1234xyz";
char *str1=strstr(str,"34");
cout << str1 << endl;
显示的是: 34xyz
*/


