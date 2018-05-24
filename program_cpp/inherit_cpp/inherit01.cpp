#include <iostream>

using namespace std;
/*继承权限总结：
 * 1.公有继承-->公有成员和受保护成员在派生类中可以直接访问，只有派生类对象可以直接访问，私有成员派生类内包括派生类对象不能直接访问
 * 2.私有继承-->派生类中基类的成员变成私有成员，基类中的公有成员和受保护成员在派生类内可以直接访问，派生类对象无法直接访问
 * 3.受保护继承-->同私有继承
 */



class A
{
public:
    int a;
    A(int a_, int b_, int c_):a(a_), b(b_), c(c_){}
private:
    int b;
protected:
    int c;
};

class B: protected A
{
public:
    B():A(10, 20, 30){
    }
    void Test()
    {
        a = 10;
    //    b = 10;
        c = 10;
    }
};

int main(void)
{
    B b1;
    return 0;
}
