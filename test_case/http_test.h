#pragma once
#include <stdio.h>
void A(int state)
{
    state += 1;
}

void switch_state(int state)
{
    switch(state){
    case 0:
        {
            A(state);
            printf("state = %d\n", state);
            break;
        }
    case 1:
        {
            printf("successful\n");
        }
    }
}

