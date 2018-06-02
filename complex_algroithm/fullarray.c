#include <stdio.h>
#include <stdio.h>

/* 交换两个数据 */
void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int isSwap(int str[], int nBegin, int nEnd)
{
    for(int i = nBegin; i != nEnd; i++)
    {
        if(str[i] == str[nEnd])
            return 0;
    }
    return 1;
}

void perm(int str[], int index, int str_size)
{
    int i = 0,j = 0;
    if(index == str_size)
    {
        /* 输出当前的排列 */
        for(i = 0; i < str_size; i++){
            printf("%d ",str[i]);
        }
        printf("\n");
    }
    else
    {
        for(j = index; j != str_size; j++)
        {
            if(isSwap(str, index, i)){
                swap(&str[j],&str[index]);
                perm(str,index+1,str_size);
                swap(&str[j],&str[index]);
            }
        }
    }
}
int main(void)
{
    int a[3] = {1,2,2};
    perm(a, 0, 3);
    return 0;
}
