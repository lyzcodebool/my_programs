#include <stdio.h>

int state = 0;
void A()
{
    state += 1;
}

void switch_state()
{
    while(1){
    switch(state){
    case 0:
        {
            A();
            printf("state = %d\n", state);
            break;
        }
    case 1:
        {
            printf("successful\n");
        }
    }

    }
}


int main(void)
{
    switch_state();
}
