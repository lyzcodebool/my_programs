#include <stdio.h>
#include <stdlib.h>

int trans_num(int num, int n)
{
    int m = 0;
    int sum = 0;
    int i = 1;
    while(i <= n){
        while(m < num){
            sum += (-1)*i;
            ++m;
            ++i;
        }
        while(m < 2*num){
            sum += i;
            ++m;
            ++i;
        }
        m = 0;
    }
    return sum;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    getchar();

    int sum = trans_num(m, n);
    
    printf("sum = %d\n", sum);
    return 0;
}
