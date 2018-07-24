#include <iostream>
using namespace std;
void test(int &a, int &b)
{
    a = b;
}


int main()
{
    int a = 1;
    int b = 2;
        
    test(a, b);
    cout<<a <<" "<<b<<endl;
    return 0;
}

