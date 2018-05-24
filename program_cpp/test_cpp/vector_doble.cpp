#include <iostream>
#include <vector>

using std::vector;
int main()
{
    vector<int> new_array(5), v, cpy;
    vector<int>::iterator it;
    for(size_t i = 0; i < new_array.size(); i++){
        std::cin>>new_array[i];
        //new_array.push_back(i);
    }
    
    for(it = new_array.begin(); it != new_array.end(); it++){
        std::cout<<*it<<std::endl;
    }

    v.push_back(10);
    v.push_back(11);
    v.push_back(12);

    for(it = v.begin(); it != v.end(); it++){
        std::cout<<*it<<std::endl;
    }

    cpy.assign(new_array.begin(), new_array.end());
    for(it = cpy.begin(); it != cpy.end(); it++){
        std::cout<<*it<<std::endl;
    }
}
