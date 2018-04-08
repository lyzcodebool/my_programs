#include <iostream>
using namespace std;

class Point{
public:
    const int fun()//const 不起作用
    {
        int a = 10;
        return a;
    }
private:
    int x, y;
};

int main(void)
{
    const int a = 0;
    int *p = (int *)&a;
    cout<<p<<"    "<<&a<<endl;
    *p = 10;
    cout<< *p<<"    "<<a <<endl;
    // int *p = &a;
    return 0;
}
