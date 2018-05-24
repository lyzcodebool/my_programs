#include <iostream>

using namespace std;

class BB{
public:
    int bb_;

};

class B1: virtual public BB
{
public:
    int b1_;
};
class B2: virtual public BB
{
public:
    int b2_;
};

class D: public B1, public B2
{
public:
    int d_;
};

int main(void)
{
    cout<<sizeof(BB)<<endl;
    cout<<sizeof(B1)<<endl;
    cout<<sizeof(D)<<endl;

    B1 b;
    long long**p;
    p  = (long long**)&b;
    cout <<&b<<endl;
    cout <<&b.bb_<<endl;
    cout <<&b.b1_<<endl;
    cout<<*p<<endl;
    cout<<p[0][0]<<endl;
    cout<<p[0][1]<<endl;
    
    int *p1 = NULL;
   cout<<sizeof(p1)<<endl;
   cout<<p<<endl;


   D d;
   cout<<"&d  "<<&d<<endl;
   cout<<"&d.b1  "<<&d.b1_<<endl;
   cout<<"&d,b2  "<<&d.b2_<<endl;
   cout<<"&d.bb  "<<&d.bb_<<endl;
   cout<<"&d.d_  "<<&d.d_<<endl;

    return 0;
}


