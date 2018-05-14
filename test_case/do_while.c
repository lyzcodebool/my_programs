#include <stdio.h>
#include <stdlib.h>

static int count = 0;

int try_equal(int a, int b)
{
    return (a == b);
}

int getID()
{
    ++count;
    return count;
}
int main(void)
{
    int a = 10;
    int seq = 0;
    int ret = try_equal(a, seq);
    printf("ret = %d\n", ret);
    do{
        seq = getID();
        printf("helloworld\n");
    }while(try_equal(a, seq));

    return 0;
}
