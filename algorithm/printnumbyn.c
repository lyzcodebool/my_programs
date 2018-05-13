#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char bool;
#define true 1
#define false 0
//没有考虑数值上限的解法
void printnumbyn(int n)
{
    int max = 1;
    int i = 0;
    while(i < n)
        max *= 10;

    for(int i = 0; i < max; ++i){
        printf("%d ", i);
    }
    putchar(10);
}

//优化方案
bool Increment(char *number)
{
    bool ifOverFlow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);

    for(int i = nLength-1; i >= 0; i--){
        int nSum = number[i]-'0'+ nTakeOver;
        if(i == nLength-1)
            nSum++;
        if(nSum >= 10){
            if(i == 0)
                ifOverFlow = true;
            else{
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else{
            number[i] = '0' + nSum;
            break;
        }
    }

    return ifOverFlow;
}

void PrintNumber(char *number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i = 0; i < nLength; ++i){
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if(!isBeginning0 )
            printf("%c", number[i]);
    }

    putchar(10);
}

void printToMaxOfNDigits(int n)
{
    if(n < 0)
        return ;
    char *number = (char *)malloc(sizeof(char) * (n+1));
    memset(number, '0', n);
    number[n] = '\0';

    while(!Increment(number)){
        PrintNumber(number);
    }
    free(number);
}

int main(void)
{
    printToMaxOfNDigits(2);

    return 0;
}
