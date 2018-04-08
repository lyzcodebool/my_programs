#include <stdio.h>
#include <stdlib.h>
#define swap(z, x, y) ((z)=(x), (x)=(y), (y)=(z));

int count = 0;

void perm(char *list, int k, int n){
    char temp;
    int i = 0;
    if(k == n){
        printf("%s\n", list);
        count++;
    }else{
        for(i = k; i <= n; i++){
            swap(temp, list[i], list[k]);
            perm(list, k+1, n);
            swap(temp, list[i], list[k]);
        }
    }
}

int main(void)
{
    char str[] = "abc";
    perm(str, 0, 2);
    
    printf("总共有count种=%d\n",count);

    return 0;
}
