#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int Combination(int *str)
{
	if(str == NULL)
		return 0;
    int sum1  = 0;
	int len = sizeof(str)/sizeof(int);
	int n = 1<<len;
	for(int i=1;i<n;i++)    //从 1 循环到 2^len -1
	{
		for(int j=0;j<len;j++)
		{
			int temp = i;
			if(temp & (1<<j))   //对应位上为1，则输出对应的字符
			{
				printf("%d",*(str+j));
			}
            sum1 ++;
		}
		printf("\n");
	}

    return sum1;
}

int main(void)
{
    int k;
    int a, count_a;
    int b, count_b;

    scanf("%d", &k);
    getchar();

    scanf("%d %d %d %d", &a, &count_a, &b, &count_b);
    getchar();

    int A[count_a];
    for(int i = 0; i < count_a; ++i)
    {
        A[i] = a;
    }
    int B[count_b];
    for(int i = 0; i < count_b; ++i)
    {
        B[i] = a;
    }

    int sum = Combination(A)+Combination(B);
    printf("%d\n",sum);

    return 0;
}
