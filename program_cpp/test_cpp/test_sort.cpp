#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

namespace ClassFoo{
    using  namespace std;
    std::vector<int> foo{1, 4, 2, 6, 5, 7};
    void printArray(vector<int> &foo){
        vector<int>::iterator Iter1;
        for(Iter1 = foo.begin(); Iter1 != foo.end(); Iter1 ++){
            cout<<*Iter1<<" ";
        }
        cout<<endl;
    }
    bool NewSort(int a, int b){
        return a > b;
    }
    void Sort(){
        sort(foo.begin(), foo.end(), NewSort);
        printArray(foo);
    }
}

int main(void){
    ClassFoo::Sort();
    return 0;
}
