#include <stdio.h>

int zipdata(int *str, int size)
{
    int count = 1;
    int i = 0;
    int temp = 0;
    while(i < size){
        if(str[i] == str[i+1])
            count++;
        else
        {
            if(count == 1){
                str[temp] = str[i];
                temp += 1;
            }else{
                str[temp] = count;
                str[temp+1] = str[i];
                temp += 2;
                printf("temp = %d i = %d count = %d  str[i] = %d\n", temp, i, count, str[i]);
                count = 1;
            }
        }
        i++;
    }
    return temp;
}

int main(void)
{
    int a[] = {1,1,1,1,2,2,2,4,5,6,6,6,6,7,8};
    for(int i = 0; i < 15; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
    int count = zipdata(a, 15);

    for(int i = 0; i < count; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
    return 0;
}
