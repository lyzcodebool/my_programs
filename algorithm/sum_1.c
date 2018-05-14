#include <stdio.h>
#include <stdlib.h>

/* long long sum_1_num(unsigned long long num) */
/* { */
/*     unsigned long count = 0; */
/*     unsigned long long i = 1; */ 
/*     for(; i <= num; ++i) */ 
/*     { */
/*         unsigned long long tmp = i; */
/*         while(tmp != 0) */
/*         { */
/*             if(tmp % 10 == 1){ */
/*                 count ++; */
/*             } */
/*             tmp /= 10; */
/*         } */
/*     } */

/*     return count; */
/* } */

int numFrom1ToN(int n)
{
    int count = 0;
    for(int i = 1; i < n; i*=10){
        int a = n/i; 
        int b = n%i;
        count += (a + 8)/10*i + ((a % 10==1)? b+1 : 0);
    }

    return count;
}

int main()
{
    int ret = numFrom1ToN(2593);
    printf("2593 中有%d 个1\n", ret);
}
