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
    cout<<"capacity:"<<v.capacity()<<endl;
    vector<int> (v).swap(v);
    cout<<"after swap capacity:"<<v.capacity()<<endl;
}

