#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout<<"A 构造函数"<<endl;
    };
    ~A(){
        cout<<"A 析构函数"<<endl;
    };
private:
    int x, y;
};
int main(void)
{
    /* A *p = new A; */
    /* delete p; */
    void *p = operator new(sizeof(A));
    //不出意外这里回调用A的构造函数
    //下面强行转换
    A *pc = static_cast<A*>(p);
    pc->~A();
    operator delete(pc);
}
