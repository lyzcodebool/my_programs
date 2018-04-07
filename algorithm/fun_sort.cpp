#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>

namespace ClassFoo
{

    using namespace std;
    struct{
        bool operator()(int a, int b){
            return a < b;
        }
    }FooLess;

    void PrintIntVector(vector<int> &foo){
        vector<int>::iterator Iter1;
        for(Iter1 = foo.begin(); Iter1 != foo.end(); Iter1 ++){
            cout<<*Iter1<<" ";
        }
        cout<<endl;
    }
    void NormalSort(){
    using namespace std;
        vector<int> foo;
        int i;
        for(i = 0; i <= 5; i++){
            foo.push_back(2*i);
        }
        int ii;
        for(ii = 0; ii <= 5; ii++){
            foo.push_back(2*ii + 1);
        }

        PrintIntVector(foo);
        std::sort(foo.begin(), foo.end(), FooLess);
        PrintIntVector(foo);
    }
}

int main(void)
{
    ClassFoo::NormalSort();
    return 0;
}
