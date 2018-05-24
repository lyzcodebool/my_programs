#include <iostream>

using namespace std;
class ObjectB;
class ObjectA{
public:
    int a;
    friend ObjectB;
private:
    int b;
protected:
    int c;

};
class ObjectB{  
public:
    void Test(ObjectA &a){
        a.a = 10;
        a.b = 20;
        a.c = 30;
    }
};

class ObjectC : public ObjectB{ 
public:
    int a_;
    void Test(ObjectA &a){
        a.a = 20;
    }
};

int main(void)
{
    ObjectA a1;

    ObjectC c1;
    c1.Test(a1); //派生类可以通过基类的公有函数来改变基类友元类的私有和受保护的数据成员
    return 0;
}
