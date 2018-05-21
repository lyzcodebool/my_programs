#include <stdio.h>
#include <stdlib.h>

#define N 8
int site[N];
int iCount = 0;

void print()
{
    iCount++;
    printf("iCount = %d\n", iCount);
    for(int i = 0; i < N; ++i)
    {
        printf("%d ", site[i]);
    }
    putchar(10);
}

int isFind(int i, int j)
{
    int k = 1;
    while(k < i){
        if(site[k] == j || abs(site[k] - j) == abs(i - k))
            return 0;
        k++;
    }
    return 1;
}
void place(int k, int n)
{
    if(k > n)
        print();
    for(int j = 1; j <= n; j ++)
    {
        if(isFind(k, j)){
            site[k] = j;
            place(k+1, n);
        }
    }
}

int main(void)
{
    place(1, 8);

    return 0;
}
