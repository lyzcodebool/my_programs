#include <iostream>

class Test{
    const int test;
};

int main(void)
{
    const int a = 100;
    int *p = (int *)&a;
    
    *p = 200;
    //注意和c语言的区别，c语言这时候a的值已经变成了200
    std::cout<<*p<<"---"<<a<<std::endl;

    return 0;
}
