#include <stdio.h>
#include <stdlib.h>

#define N 8
static int iCount = 0;
int site[N];

void print(){
    iCount++;
    printf("iCount = %d\n", iCount);

    for(int i = 0; i < N; ++i)
    {
        printf("%d ", site[i]);
    }
    putchar(10);
}

int  isFind(int k, int i) //检查第k行第i列是否可以放置皇后
{
    int j = 1;
    while(j < k)
    {
        if(site[j] == i || abs(site[j]-i) == abs(k-j))
            return 0;
        j++;
    }
    return 1;
}

//放置皇后到棋盘上，从第k行开始，检查每个列
void place(int k, int n)
{
    if(k > n)
        print();
    else{
        for(int j = 1; j <= n; j ++){
            if(isFind(k, j)){
                site[k] = j;
                place(k+1, n);
            }
        }
    }
}


int main(void)
{
    place(1, N);
    return 0;
}
