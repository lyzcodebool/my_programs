#include <stdio.h>

int main(void)
{
    int n, m, s = 0, i;
     printf ("N M = ");
     scanf("%d%d", &n, &m);
     for (i = 2; i <= n; i++)
     {
         s = (s + m) % i;
     }
     printf ("\nThe winner is %d\n", s+1);
}
