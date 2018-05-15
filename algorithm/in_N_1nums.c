#include <stdio.h>
#include <stdlib.h>

/*求1到n数字中1的个数*/
unsigned long Sums1(unsigned long long n)
{
    unsigned long long iCount = 0;
    unsigned long long iFactor = 1;
    unsigned long long iLowerNum = 0;
    unsigned long long iHighNum= 0;
    unsigned long long iCurrNum = 0;

    while(n / iFactor != 0){
        iLowerNum = n-(n/ iFactor)*iFactor;
        iCurrNum = (n/iFactor)%10;
        iHighNum = n/(iFactor * 10);

        switch(iCurrNum)
        {
            case 0:
                iCount += iHighNum*iFactor;
                break;
            case 1:
                iCount += iHighNum*iFactor + iLowerNum + 1;
                break;
            default:
                iCount += (iHighNum + 1)*iFactor;
                break;
        }
        iFactor *= 10;
    }
    return iCount;
}

int main(void)
{
    unsigned long long  n;
    scanf("%llu", &n);
    unsigned long numof1 = Sums1(n);
    
    printf("sum of num 1 is %lu\n", numof1);
    return 0;
}
