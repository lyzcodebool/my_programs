#include <iostream>

using namespace std;

//拥有纯虚函数的类叫做抽象类，抽象类不能被实例化
//抽象类的析构函数通常是虚析构函数，放置发生内存泄漏
class Base 
{
public:
    virtual ~Base() = 0;
};

int main(void)
{


    return 0;
}

