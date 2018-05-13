#include <stdio.h>

enum
{
    a = 100,
    b = 200,
    c,

}enum_size;
int main()
{
    printf("%ld\n", sizeof(enum_size));
}
