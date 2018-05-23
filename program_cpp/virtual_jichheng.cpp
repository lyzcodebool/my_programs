#include <iostream>

using namespace std;

class A {
public:
    int a_1;
    A(int a): a_1(a){
        cout<<"A"<<endl;
    }
    ~A(){};
};
class A_1:virtual public A{
public:
    A_1(int a):A(a){
        cout<<"A_1"<<endl;
    }
};
class A_2:virtual public A{
public:
    A_2(int a):A(a){
        cout<<"A_2"<<endl;
    }
};

class A_1_2: public A_2, public A_1
{
public:
    A_1_2(int a):A(a), A_2(a), A_1(a){
        cout <<"A_1_2"<<endl;
    }
};


int main(void){
    A_1_2 a(10);
}


