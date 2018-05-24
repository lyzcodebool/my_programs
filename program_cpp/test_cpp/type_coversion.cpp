#include <iostream>

using namespace std;

class A{
public:
    A(){ cout<<"construct!"<<endl; }
    void fun(){cout<<"A::fun"<<endl;}
    virtual void fun_A(){cout<<"virtual void A::fun_A" <<endl;}
private:
    int x, y;
};


class B:public A{
public:
    B(){cout <<"B construct!" << endl;}
    void fun_A(){cout<<"virtual void fun_B" << endl;}
    void fun1(){cout<<"B::fun1" <<endl;}
    int u;
private:
    int k, l;
};

int main(void)
{
    //dynamic_cast和static_cast的区别
    //上行转换和下行转换的异同
    A *pf, f;
    B *pd, s;
    pf = &f;//基类指针指向基类对象
    pd = static_cast<B*>(pf);//这种转换不安全,行为不确定
    if(pd != NULL){
        pd->fun_A();
        pd->fun1();
        pd->u = 1;
        cout<<"u = "<<pd->u<<endl;
    }
    


    //const_cast的用法
    const int curr = 10;
    const int *curr_1 = &curr;
    int *ptr = const_cast<int *>(&curr);
    *ptr = 1;
    cout<<*ptr<<curr<<"   "<< ptr<<  "  "<<&curr<<endl;
    *ptr = 100;
    cout<<*ptr<<curr<<"   "<< ptr<<  "  "<<&curr<<endl;
    ptr += 1;
    *ptr = 200;
    cout<<*ptr<<curr<<"   "<< ptr<<  "  "<<&curr<<endl;
    cout<<"const curr_1 :"<<curr_1<<"    "<<*curr_1<<endl;
    curr_1 += 1;;
    cout<<*ptr<<curr<<"   "<< ptr<<  "  "<<&curr<<endl;
    cout<<"const curr_1 :"<<curr_1<<"    "<<*curr_1<<endl;

    int var = 20;
    const int *p = &var;
    int *mmm = const_cast<int*>(p);
    *mmm = 21;
    
    cout<<"var = "<<var<<"*p = "<< *p <<endl;

    return 0;
}
