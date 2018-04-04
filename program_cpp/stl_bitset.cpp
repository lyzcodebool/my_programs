#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main(void)
{
    bitset<32> a; //a的大小是三十二位二进制，全部是0
    cout<<a<<endl;

    bitset<16> b (0xffff);//1111 1111 1111 1111
    cout<<b<<endl;

    bitset<32> c (0xffff);
    cout<<c<<endl;


    bitset<128> d (0xffff);
    cout<<d<<endl;

    bitset<32> e (128);
    cout<<e<<endl;

    string str("11111110000000011001101");
    bitset<32> f(str, 5, 4);
    cout<<f<<endl;
    
    d.set();
    cout << d <<endl;
    d.reset();
    cout << d <<endl;
    string str1 = d.to_string();
    cout << "string :"<< str1 << endl;

    bool m = d.operator[](5);
    cout << m<< endl;

    return 0;
}

