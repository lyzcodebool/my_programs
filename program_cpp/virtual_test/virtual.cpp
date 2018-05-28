#include <iostream>

using namespace std;

class Base{
public:
    int b_;
    void Fun1(){ cout<<"Base::Fun1..."<<endl; }
    virtual void Fun2(){cout<<"Base::Fun2..."<<endl;}
    virtual void Fun3(){cout<<"Base::Fun3..."<<endl;}

    virtual ~Base(){ cout<<"~Base"<<endl; } //定义成虚函数，防止发生内存泄漏，防止只释放基类内存,派生类内存无法析构
private:
    int a_;
};

class Child:public Base
{
public:
    void Fun1(){ cout<<"Child::Fun1..."<<endl; }
    void Fun2(){ cout<<"Child::Fun2..."<<endl; }
    virtual void Fun3(){cout<<"Child::Fun3..."<<endl;}
    ~Child(){ cout<<"~Child"<<endl; }
};

typedef  void (*FUN)();

int main(void)
{
    Base p;
    /* p = new Child; */
    /* p->Fun1(); */
    /* p->Fun2(); */
    /* p->Fun3(); */

    long **q;
    q = (long **)&p;
    cout<<&p.b_<<endl;
    long **m;
    m = (long **)&p.b_;
    cout<<"virp: "<<*q<<endl;

    FUN fun1 = (FUN)q[0][1];
    fun1();
    FUN fun2 = (FUN)q[0][2];
    fun2();
    cout<<sizeof(Base)<<endl;

    /* delete  p; */


    /* Child c; */
    /* long **q; */
    /* q = (long **)&c; */
    /* cout<<"virp: "<<*q<<endl; */

    /* FUN fun = (FUN)q[0][0]; */
    /* cout<<"q[0][0] :"<<&q[0][0]<<endl; */
    /* fun(); */
    /* FUN fun1 = (FUN)q[0][1]; */
    /* fun1(); */
    return 0;
}
