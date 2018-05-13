#include <stdio.h>
//求整数的次方
//通过位运算判断奇偶，这个程序的优势在于减小了乘的次数
double PowerWithExponent(int base, unsigned int exponent)
{
    if(exponent == 0)
        return 0;
    if(exponent == 1)
        return base;
    int result = PowerWithExponent(base, exponent >> 1);
    result *= result;
    if((exponent & 0x1) == 1)
        result *= base;

    return result;
}

int main()
{

    return 0;
}
