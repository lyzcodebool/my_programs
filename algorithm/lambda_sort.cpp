#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>

namespace ClassFoo{
    void PrintIntVector(std::vector<int> &foo){
        std::vector<int> ::iterator Iter1;
        for(Iter1 = foo.begin(); Iter1 != foo.end(); Iter1++){
            std::cout<<*Iter1<<" ";
        }
        std::cout<<std::endl;
    }

    void NormalSort3(){
        using namespace std;
        vector<int> foo;
        int i;

        for(i = 0; i <= 5; ++i){
            foo.push_back(2*i);
        }
        int ii;
        for(ii = 0; ii <= 5; ii++){
            foo.push_back(2*ii+1);
        }

        PrintIntVector(foo);
        std::sort(foo.begin(), foo.end(), [](int a, int b){
            return b < a;
        });
        PrintIntVector(foo);
    }
}

int main(void)
{
    ClassFoo::NormalSort3();
    return 0;
}
