#include <stdio.h>

int NumberOf1(int n)
{
    int count = 0;
    while(n){
        if(n & 1){
            count ++;
        }
        n = n >> 1;
    }
    return count;
}


int NumberOf1_2(int n)
{
    int count = 0;
    unsigned int flags = 1;
    while(flags){
        if(n & flags)
            count ++;
        flags = flags << 1;
    }
    return count;
}

int  main(void)
{
    

    return 0;
}
