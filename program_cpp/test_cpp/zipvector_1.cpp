#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
    //insert code here...
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;
    cout<<"clera before"<<" ";
    for(it = v.begin(); it != v.end(); it ++){
        cout<<*it<<"\t";
    }

    cout<<endl;
    cout<<"clear before capacity:"<<v.capacity()<<endl;
    v.clear();
    cout<<"after clear"<<" ";
    for(it = v.begin(); it != v.end(); it++){
        cout<<*it<<"\t";
    }

    cout<<endl;
    cout<<"after clear capacity:"<<v.capacity()<<endl;
    return 0;
}
