#include <iostream>
//派生类不继承基类的构造函数、析构函数、=函数
//友元关系不传递，友元关系不被继承。
//静态成员无所谓继承，是共享的，
using namespace std;
class Obj{
    public:
    private:
        int obj_;
};
class Base{
public:
    int x_;
    Base(int a_):y_(a_){}
    ~Base(){
    }
    /* Base(const Base &other):y_(other.y_){} */
    /* void GetValObj()const{ */
    /* } */
    int y_;
private:
     int n_ = 10;
/*     Obj obj1_; */
/* protected: */
    /* int z_; */
};

class Child:public Base
{
public:
    Child(int m):Base(10), m_(m){}
    int m_;
private:
};
//向下转型不安全,没有自动转换机制
int main(void)
{
    Base b(10);
    Base test(b);

    Child c(1100);

    Base *p = &b;
    Child *q = &c;

    //q = p; //派生类对象不能等于基类对象指针呢
    q = static_cast<Child*>(p);//基类对象指针可以强制转化为派生类对象指针,但是不安全
    p = q; //基类对象指针(引用)可以等于派生类对象指针(引用)， 将派生类对象看成是基类对象, 将派生类对象看成是基类对象
    //私有 或者受保护继承的时候，//基类对象指针(引用)可以等于派生类对象指针(引用)，但是必须进行强制类型转换static_cast不行
    //要使用reinterpret_cast<>()
    //b = c; //派生类对象可以转化成基类对象, 会产生对象切割, 派生类特有成员消失
    c = reinterpret_cast<Child *>(b);
    //私有或者保护继承的时候，派生类对象无法转化为基类对象
    cout<<b.y_<<endl;
    cout<<c.m_<<endl;
    cout<<test.y_<<endl;
    
}
