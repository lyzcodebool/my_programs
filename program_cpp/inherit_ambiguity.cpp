#include <iostream>
using namespace std;

class A{
public:
    A(){cout<<"A 构造...."<<endl;}
    void fun(){
        cout<<"A::fun"<<endl;
    }
    void gun(){
        cout<<"A::gun"<<endl;
    }
};

class B{
public:
    B(){cout<<"B 构造...."<<endl;}
    void fun(){
        cout<<"B::fun"<<endl;
    }

    void dun(){
        cout<<"B::dun"<<endl;
    }
};

class C:public A, public B{ //这里AB的继承顺序决定了构造的顺序，从左往右
public:
    C(){cout<<"C 构造...."<<endl;}
};

class D:virtual public A{
public:
    D(){cout<<"D 构造...."<<endl;}
    void kun(){
        cout<<"D::kun"<<endl;
    }
};

class E:virtual public A{
public:
    E(){cout<<"E 构造...."<<endl;}
};

class F:public E, public D{ //这里AB的继承顺序决定了构造的顺序，从左往右
public:
    F(){cout<<"F 构造...."<<endl;}
};
int main(void)
{
    C test;
    //test.fun();//二义性
    //解决办法：
    //test.A::fun();
    //test.B::fun();
    //注意这种二义性虚继承无法解决
    //在类中fun(){ A::fun(); }
    test.dun();
    test.gun();
    F test2;
    test2.fun();//二义性
    //解决办法：
    //test2.D::fun();
    //test2.E::fun();
    //虚继承


    return 0;
}
