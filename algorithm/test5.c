#include <stdio.h>
#include <stdlib.h>

int sum_trans(int *a, int n, int m){
    int i = 1, j = 1;
    while(i < n && j < n){
        if(i == m){
            while(i <= 2*m-1) {
                a[j++] *= -1;
                i++;
            }
            i = 0;
        }
        i++;
        j++;
    }
    int sum = 0;
    for(int p = 0; p < n; p ++){
        sum += a[p];
    }
    return sum;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    int a[n];  
    for(int i = 0; i < n; ++i){
        a[i] = (i+1)*(-1);
    }
    int sum = sum_trans(a, n, m);
    printf("%d\n", sum);
}
