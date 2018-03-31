#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void)
{
    int temp;
    scanf("%d", &temp);
    getchar();
    int a[temp];
    for(int i = 0; i < temp; i++){
        scanf("%d", &a[i]);
        getchar();
    }
    putchar(10);
    int j = temp-1;
    int i = 0;
    while(i < j){
        while(i < j && a[i] != 0)
            i++;
        while(i < j && a[j] == 0)
            j--;
        if(i < j){
            swap(&a[i], &a[j]);
        }
    }

    for(int n = 0;  n < temp; ++n){
        printf("%d\n", a[n]);
    }

}
