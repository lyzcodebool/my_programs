#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//swap_test并不能完成交换，临时变量在栈上，出了作用域自动销毁
void swap_test(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void)
{
    int a[] = {1, 2};
//    swap(&a[0], &a[1]);

    /* for(int i = 0; i < 2; ++i){ */
    /*     printf("%d ", a[i]); */
    /* } */
    /* putchar(10); */
    swap_test(a[0], a[1]);
    for(int i = 0; i < 2; ++i){
        printf("%d ", a[i]);
    }
    putchar(10);
}
