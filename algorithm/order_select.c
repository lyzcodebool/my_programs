#include <stdio.h>

int SequentialSearch(int *a, int len, int x){
    for(int i = 0; i < len; i++)  {
        if(a[i] == x) {
            return i;
        }
    }

    return 0;
}

int main()
{
    int a[10] = {1, 3, 4, 5, 6 };

    int len = sizeof(a)/sizeof(int);
    int i = SequentialSearch(a, len, 3);
    if(i != 0)
        printf("search the num = %d\n", i);

    if(i == 0)
        printf("no the num!\n");

    return 0;
}
