#include <iostream>

class Test{
public:
    Test(int x, int y, int z):a(x),c(z){}

private:
    const int a;
    static const int b;
    int c;
};

//const int Test::b = 1;

int main(void)
{
    const int a = 100;
    int *p = (int *)&a;
    
    *p = 200;
    //注意和c语言的区别，c语言这时候a的值已经变成了200
    std::cout<<*p<<"---"<<a<<std::endl;

    return 0;
}
