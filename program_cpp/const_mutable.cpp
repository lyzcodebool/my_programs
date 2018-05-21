#include <iostream>

using namespace std;
class Test{

public:
    Test(int x, int y):a(x), b(y){
        cout<<"construction..."<<endl;
    };
    void test1()const;
    void test2();
private:
    int a;
    mutable int b;
};

void Test::test1()const{
    this->b = 10;
}

void Test::test2(){
    this->a = 10;
    this->b = 10;
}

int main(void)
{
    Test *t = new Test(1, 1);
    t->test1();
}





