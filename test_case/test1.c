#include <stdio.h>
#define n1 10*10*10
#define n2 10*10*10*10
#define n3 10*10*10*10*10*10


int main(void)
{
    int N;
    scanf("%d", &N);
    getchar();
    if(N < 0 || N > 10)
        return 0;

    int *a[N];
    scanf("%d", &a[0][0]);
    getchar();
    int n = a[0][0];
    int i, j;
    for(i = 0; i < N; ++i){
        for(j = 1; j < n; ++j){
            scanf("%d", &a[i][j]);
        }
        int x = a[i][j];
        for(j = 1; j < n; j++){
            if(x+a[i][j] <= a[i][n] && a[i][j]-x >= a[i][1]){

            }

        }
        scanf("%d", &n);
        getchar();
        a[i][0] = n;
    }
}
