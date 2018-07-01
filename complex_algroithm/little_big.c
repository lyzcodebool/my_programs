#include <stdio.h>
/* 小端字节需又称为主机字节序 */

typedef union{
    short value;
    char union_type[sizeof(short)];
}type;

int main(){
    type a;
    a.value = 0X1234;
    if(a.union_type[0] == 12 && a.union_type[1] == 34){
        printf("big");
    }else{
        printf("small");
    }

    putchar(10);
    return 0;
}

