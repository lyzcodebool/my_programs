#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>

namespace ClassFoo{
    
    int RandomNumber() {return (std::rand() % 100);}

    void PartialSort1(){
        std::srand(unsigned (std::time(0)));
        std::vector<int> foo(15);

        std::generate(foo.begin(), foo.end(), RandomNumber);
        std::partial_sort(foo.begin(), foo.begin()+7, foo.end());
    }

}

int main(void){
    ClassFoo::PartialSort1();
    return 0;
}
