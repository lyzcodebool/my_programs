#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned)time(NULL));
    
    for(int i = 0; i < 10; i ++){
        printf("%d ", rand() % 10);
    }
    putchar(10);

    for(int i = 0; i < 10; ++i){
        printf("%d ", rand()%(10-i) + i);
    }

    putchar(10);
    return 0;
}
