#include <iostream>
using namespace  std;
class Base {  
public:  
    Base() : value(1) {}  
    ~Base() {}  
    virtual void print() {  
        std::cout << "This is Base class..." << std::endl;  
        std::cout << "value is " << value << std::endl;  
    }  
    int value;  
};  
 
class FromBase : public Base {  
public:  
    FromBase() : value(2) {}  
    ~FromBase() {}  
    void print() {  
        std::cout << "This is FromBase class..." << std::endl;  
        std::cout << "value is " << value << std::endl;  
    }  
    int value;  
};  

class Test1  
{  
public:  
    Test1();  
    ~Test1();  
  
    void test();  
};  
  
Test1::Test1() {  
    cout << "class Test1" << endl;  
}  
  
Test1::~Test1() {  
    cout << "class Test1 destructor..." << endl;  
}  
  
void Test1::test() {  
    Base base;  
    FromBase fbase;  
    Base *p = NULL;  
    cout << "base's address is: " << &base << endl;  
    cout << "fbase's address is: " << &fbase << endl;  
    cout << "point p's address is: " << p << endl;  
  
    p = &base;  
    cout << "point p's address is: " << p << endl;  
    p->print();  
    cout << "point value's address is: " << &(p->value)  
        << ", member value's address is: " << &base.value  
        << ", value is "<< p->value << endl;  
  
    p = &fbase;  
    cout << "point p's address is: " << p << endl;  
    p->print();  
    cout << "point value's address is: " << &(p->value)  
        << ", member value's address is: " << &fbase.value  
        <<", 对象的value is "<<fbase.value
        << ", value is " << p->value << endl;  
}  

int main(void)
{
    Test1 test;
    test.test();

    return 0;
}
/*单一继承子类重写父类中的虚函数*/
/*class Base1 {*/  
/*public:*/  
/*    Base1() : value(1) { cout << "Base1 constructor..." << endl; }*/  
/*    ~Base1() { cout << "Base1 destructor..." << endl; }*/  
  
/*    virtual void f1() { cout << "base1 function f1..." << endl; }*/  
/*    virtual void f2() { cout << "base1 function f2..." << endl; }*/  
/*    virtual void f3() { cout << "base1 function f3..." << endl; }*/  
  
/*    int value;*/  
/*};*/  
  
/*class FromBase : public Base1 {*/  
/*public:*/  
/*    FromBase() : value(2) { cout << "FromBase constructor..." << endl; }*/  
/*    ~FromBase() { cout << "FromBase destructor..." << endl; }*/  
  
/*    virtual void f2() { cout << "FromBase function f2..." << endl; }*/  
  
/*    int value;*/  
/*};*/
/*class Test2{*/
/*    Test2();*/
/*    ~Test2();*/
/*    void testBase1(long **ptl);*/
/*    void testFromBase(long **ptl);*/
/*    void test2();*/
/*};*/

/*Test2::Test2(){};*/
/*Test2::~Test2(){};*/
/*void Test2::testBase1(long **ptl) {*/  
/*    Base1 *p;*/  
/*    p = (Base1*)*ptl;*/  
/*    cout << "address base1 is: " << p << endl;*/  
/*    cout << "value vptr is: = 0x" << uppercase << hex << **ptl << endl;*/  
/*    cout << "address base1 value is：" << &(p->value) << endl;*/  
  
/*    long *vptr = (long*)**ptl;*/  
  
/*    Fun fun = (Fun)*(vptr + 0);*/  
/*    fun();*/  
/*    fun = (Fun)*(vptr + 1);*/  
/*    fun();*/  
/*    fun = (Fun)*(vptr + 2);*/  
/*    fun();*/  
/*}*/  
  
/*void Test2::testFromBase(long **ptl) {*/  
/*    cout << "address FromBase is: " << ptl << endl;*/  
/*    cout << "value vptr is: = 0x" << uppercase << hex << **ptl << endl;*/  
  
/*    long *vptr = (long*)**ptl;*/  
  
/*    Fun fun = (Fun)*(vptr + 0);*/  
/*    fun();*/  
/*    fun = (Fun)*(vptr + 1);*/  
/*    fun();*/  
/*    fun = (Fun)*(vptr + 2);*/  
/*    fun();*/  
/*}*/  
  
/*void Test2::test2() {*/  
/*    long **ptl = NULL;*/  
  
/*    Base1 base1;*/  
/*    FromBase fbase;*/  
      
/*    Base1 *p = &base1;*/  
  
/*    ptl = (long**)(&p);*/  
/*    testBase1(ptl);*/  
  
/*    cout << endl << endl;*/  
  
/*    p = &fbase;*/  
/*    ptl = (long**)(&p);*/  
/*    testFromBase(ptl);*/  
/*}*/  
/*int main(void)*/
/*{*/
/*    Test2 test;*/
/*    test.test2();*/
/*}*/
