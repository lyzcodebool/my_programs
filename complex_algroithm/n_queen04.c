#include <stdio.h>
#include <stdlib.h>

#define N 8 
int iCount = 0;
int site[N];

void print()
{
    iCount ++;
    printf("iCount = %d\n", iCount);
    for(int i = 0; i < N; ++i)
    {
        printf("%d ", site[i]);
    }

    printf("\n");
}

int isFind(int i, int j)
{
    int k = 1;
    while(k  < i)
    {
        if(site[k] == j || abs(site[k] - j) == abs(i - k))
            return 0;
        k++;
    }
    return 1;
}

void place(int i, int n)
{
    if(i > n)
        print();
    else 
    {
        for(int j = 1; j <= n; j++)
        {
            if(isFind(i, j)){
                site[i] = j;
                place(i+1, n);
            }
        }
    }
}


int main()
{
    place(1, N);
}
