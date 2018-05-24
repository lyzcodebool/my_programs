#include <iostream>
#include <vector>
//压缩vector方法1：
//
using namespace std;
int main(int argc, char *argv[])
{
    //insert code here
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout<<*it<<endl;
    }
    cout<<"befor copy capacity:"<<v.capacity()<<endl;
    vector<int> v1(v);
    for(it = v1.begin(); it != v1.end(); it++){
        cout<<*it<<endl;
    }
    cout<<"after copy capacity:"<<v1.capacity()<<endl;
}

