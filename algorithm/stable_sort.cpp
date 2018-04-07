#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

namespace ClassFoo{
    //返回第一个元素是否比第二个元素大
    bool UDgreater(int elem1, int elem2){
        return elem1 > elem2;
    }
    void StableSort(){
        using namespace std;
        vector<int> v1;
        vector<int>::iterator Iter1;

        int i;
        for(i = 0; i <= 5; i++){
            v1.push_back(2*i);
        }

        for(i = 0; i <= 5; i++){
            v1.push_back(2*i);
        }

        for(Iter1 = v1.begin(); Iter1 != v1.end(); Iter1 ++){
            cout <<*Iter1<<" ";
        }
        cout<<endl;

        // 按升序排序，使用默认的二元谓词函数
        stable_sort(v1.begin(), v1.end());
        for(Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++){
            cout<<*Iter1<<" ";
        }
        cout<<endl;

        //按降序排列， 提供二元谓词函数
        stable_sort(v1.begin(), v1.end(), UDgreater);
        for(Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++){
            cout<<*Iter1<<" ";
        }
        cout<<endl;
    }
}

int main(void)
{
    ClassFoo::StableSort();
    return 0;
}
