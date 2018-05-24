#include <iostream>


class Point{
public:
    virtual void f(){std::cout<<"Point::f()"<<std::endl;}
    virtual void g(){std::cout<<"Point::g()"<<std::endl;}
    virtual void p(){std::cout<<"Point::p()"<<std::endl;}
};

int main(void)
{
    typedef  void(*Fun)(void);
    Point test;
    Fun pFun = NULL;

    std::cout<<"虚函数表地址："<<(int *)(&test)<<std::endl;
    std::cout<<"虚函数表第一个函数地址："<<(int *)*(int *)(&test)<<std::endl;

    pFun =(Fun)*((int *)*(int *)(&test));
    pFun();

    pFun = (Fun)*((int *)*(int *)(&test)+0);
    pFun();
    pFun = (Fun)*((int *)*(int *)(&test)+1);
    pFun();
    pFun = (Fun)*((int *)*(int *)(&test)+2);
    pFun();
}
