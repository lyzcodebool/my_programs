#include <iostream>

//派生类C继承了A的友元类
//
//需要注意的是友元类的传递问题，一个友元类B的友元类，对将B设置为友元类的类没有特殊的访问权限
//友元类函数的传递和友元类的传递和继承规则相同
//一个友元类的友元函数对设置这个类为友元类的类没有特殊访问权限
using namespace std;

class B;
class A{
private:
    int a;
public:
    int b;

    friend B;
};

class B{
public:
    int b_;

    void Test(A &a){
        a.a = 10;
        a.b = 10;
    }
    void fun(B &b){
        b.b1_ = 10;
        b.b2_ = 10;
        b.b_ = 10;
    }
private:
    int b1_;
protected:
    int b2_;
};


class C: public A{
public:
    void fun(A &a){
        a.b  = 10;
        /* a.a = 20;//私有成员无法直接访问 */
    }
};

int main(void){


    return 0;
}
