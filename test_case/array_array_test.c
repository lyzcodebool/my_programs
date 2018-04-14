#include <stdio.h>
#include <stdlib.h>


int main(void){

    int a[2][2] = {{1,2}, {3, 4}};
    printf("a[0] = %p &a[0][0] = %p a = %p\n", a[0], &a[0][0], a);//首地址
    printf("a+1 = %p  **(a+1) = %d\n", a+1, **(a+1));//a是二级指针
    printf("a+1 = %p  \n", a+1);//跳到下一行
    printf("a[0]+1 = %p  a[0]+1 = %d\n", a[0]+1, *(a[0]+1));//：跳到下个元素 
    printf("&a[0][0]+1 = %p  \n", &a[0][0]+1);//跳到下个元素 
    printf("a[0]+1 = %p  *(a[0]+1) = %d\n", a[0]+1, *(a[0] + 1));//跳到下个元素
    printf("a[0]+2 = %p  *(a[0]+2) = %d\n", a[0]+2, *(a[0] + 2));//跳到下个元素
    printf("&a+1 = %p  \n", &a+1);

    return 0;
}
