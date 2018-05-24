#include <iostream>

using namespace std;

class ObjectA{
public:
    int a;
private:
    int b;
protected:
    int c;
};

class ObjectB: ObjectA //默认私有继承
{
public:
    void Test()
    {
        a = 10;
        c = 30;
    }
};

int main(void)
{
    ObjectB b1;
    b1.a = 30;

    return 0;
}
