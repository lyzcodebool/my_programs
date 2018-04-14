#include <iostream>
using namespace std;

class Point{

public:
    //重载，在一个类当中，有无virtual无影响
    void fun(int a, int b){cout<<"FUN_2"<<endl;}
    int fun(int a){cout<<"A::fun"<<endl;return a;}
    //覆盖，必须是不同的类中，基类带virtual
    virtual int func(int a){cout<<"A::virtual func"<<endl;return a;}
    //隐藏,位于不同的类中，无论virtual，参数不同。
    //位于不同类中函数名和参数都想同，没有virtual
    //1）如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual
//关键字，基类的函数将被隐藏（注意别与重载混淆）。
//（2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual
//关键字。此时，基类的函数被隐藏（注意别与覆盖混淆）。
};

class B:public Point{
public:
    void fun(int a, int b){cout<<"B::fun"<<endl;}
    int func(int a){cout<<"B:func"<<endl;}
    int func(int a, int b){cout<<"B::func 隐藏"<<endl;}
};

int main()
{
    B d;
    Point *point = &d;
    B *b = &d;

    point->fun(1,2);//B::fun
    point->fun(1);
    point->func(1);//B::func
    
    b->fun(1, 2);//隐藏B::fun
    b->func(1);//B::func
    b->func(1, 2);//B::func隐藏
    return 0;
}
