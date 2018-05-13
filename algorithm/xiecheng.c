#include <stdio.h>
int function(void) {
static    int i, state = 0;
  switch (state) {
    case 0: goto LABEL0;
    case 1: goto LABEL1;
  }
  LABEL0: /* start of function */
  for (i = 0; i < 1; i++) {
    state = 1; /* so we will come back to LABEL1 */
    return i;
    LABEL1: printf("comed!\n"); /* resume control straight after the return */

  }
}

int main(void)
{
    int n = 0;
    while(n < 10)
    {
        printf("%d\n", function());
        n++;
    }
}
