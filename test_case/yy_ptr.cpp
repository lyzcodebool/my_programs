#include <iostream>

using namespace std;
class Point{
    int x;//4
    int y;//4
    virtual int fun(int x, int y){}//8
};//16
//引用和指针的区别
int main(void)
{
    int a = 10;
    int &b = a;
    int c = 10;
    int *p = &c;
    int *q = p;
    //1.引用必须在使用的时候初始化，绑定了以后不能再更改，指针可以置null
    //2.*p指向数据的内存单元，是内存单元的地址，引用只是对象的别名
    //3.p++是地址++; 引用++是对象++
    b++;
    p++;
    cout<<b<<" "<<a<<endl;
    cout<<p<<" "<<c<<" "<<q<<" "<<*p<<endl;
    //引用内部是指针实现，可以通过汇编代码来看，x在&x存入eax寄存器，b在&b（比x低4字节），把eax的值存入&b中，其实相当于指针存的数据的地址。
    int x = 1;
    int y = 2;
    cout<<"&x:"<<&x<<"  &y:"<<&y<<"  &b1:"<<&y-1<<"   &b2:"<<&x+1<<"  b:"<<*(&y -1)<<endl;
    //const引用的使用要特别注意不能给const引用赋值非引用对象
    const int &t = 2;//正确
    const int &k = y;//后面会出现问题
    //k++;//即使编译成功，y的值也不会改变，因为当const引用赋值非引用对象的时候，会有个临时变量temp = y; &k = temp; 所以
    //你通过引用来改变y的值实际改变的是temp的值，y并不会改变，所以编译次直接杜绝了这个错误。
    const int &l = b+x;//正确
    //4.网上说指针可以用const引用个不能加const其实是错误的
    cout<<"t:"<<t<<"  k:"<<k<<" l:"<<l<<endl;
    //5.指针可以有多级，引用不可以
    const int *m = &a;
    //const int &&n = a;//rvalue reference to type 'const int' cannot bind to lvalue of type 'int'
    //看看赋值const int
    const int aa = 10;
    //const int &&nn = aa;//rvalue reference to type 'const int' cannot bind to lvalue of type 'const int'
    //6.指针sizeof得到指针本身的大小，sizeof(引用)得到的是被引用对象的大小。
    Point point;
    Point &d = point;
    cout<<"sizeof(引用):"<<sizeof(b)<<"  szieof(point):"<<sizeof(d)<<endl;
    //露了一点：指针可以改变指向，引用一旦绑定就不能改变
    return 0;
}
