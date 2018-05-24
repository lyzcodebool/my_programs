#include <iostream>

using namespace std;

class Point{

public:
    Point(int x):a(x){}
private:
    const int a;
};

int main()
{
    Point b(10);
    const_cast<int>(b.a) = 20;

}
