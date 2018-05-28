#include <stdlib.h>
#include <stdio.h>

//n皇后
#define N 8
int site[N];
int iCount = 0;

typedef enum{
    FALSE,
    TRUE
}BOOL;

void print(){
    iCount ++;
    printf("iCount = %d\n", iCount);
    for(int i = 0; i < N; i++){
        printf("%d ", site[i]);
    }
    putchar(10);
}

BOOL isFind(int i, int j){
    int k = 1;
    while(k < i)
    {
        if(site[k] == j || abs(i - k) == abs(site[k] - j))
            return FALSE;
        k++;
    }
    return TRUE;
}

void n_queen(int i, int n){
    if(i > n){
        print();
    }
    else{
        for(int j = 1; j <= n; j++){
            if(isFind(i, j)){
                site[i] = j;
                n_queen(i+1, n);
            }
        }
    }
}

int main(void)
{
    n_queen(1, 8);

    return 0;
}
