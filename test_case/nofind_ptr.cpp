#include <iostream>

using namespace std;
//悬挂指针用valgrind来检测
//
class Point{
public:

private:
};

int main(void)
{
    Point m;
    int *p;
    {
        int a = 10;

        p = &a;

        cout<<a<< " "<<&a<<endl;
    }
    int *b = new int;
    b = p;
    delete b;
    b = NULL;

    cout<<*p<<" "<<" "<<p<<" "<<endl;

    return 0;
}
