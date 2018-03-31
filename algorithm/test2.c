#include <stdio.h>
#define N 3
int main(void)
{
    int a[N][N];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            scanf("%d", &a[i][j]);
        }
        getchar();
    }

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < i ; j++){
            int temp = 0;
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = N-1; j >= N/2; j--){
            int temp = 0;
            temp = a[i][j];
            a[i][j] = a[i][N-j-1];
            a[i][N-j-1] = temp;
        }
    }

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            printf("%d ", a[i][j]);
        }
        putchar(10);
    }

}
