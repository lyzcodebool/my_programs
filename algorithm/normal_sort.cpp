#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

namespace ClassFoo
{
    //返回第一个元素是否比第二个元素大
    bool UDgreater(int elem1, int elem2){
        return elem1 > elem2;
    }

    void NormalSort(){
        using namespace std;
        vector <int> foo;
        vector <int>::iterator Iter1;
        int i;
        for(i = 0; i <= 5; i++){
            foo.push_back(2*i);
        }

        int ii;
        for(ii = 0; ii <= 5; ii++){
            foo.push_back(2*ii+1);
        }

        cout<<"Orignal vector foo = (";
        for(Iter1 = foo.begin(); Iter1 != foo.end(); Iter1++){
            cout<<*Iter1<<" ";
        }

        cout<<")"<<endl;

        //按升序排序，使用默认的二元谓词函数
        sort(foo.begin(), foo.end());
        cout<<"Sorted vector foo = (";
        for(Iter1 = foo.begin(); Iter1 != foo.end(); Iter1++){
            cout<<*Iter1<<" ";
        }
        cout<<")"<<endl;

        //按降序排列，提供二元谓词函数
        sort(foo.begin(), foo.end(), greater<int>());
        cout<<"Resorted (greater) vector foo = (";
        for(Iter1 = foo.begin(); Iter1 != foo.end(); Iter1++){
            cout<<*Iter1<<" ";
        }

        cout<<")"<<endl;

        //使用自己的二元谓词函数
        sort(foo.begin(), foo.end(), UDgreater);
        cout<<"Resorted (UDgreater) vector foo = (";
        for(Iter1 = foo.begin(); Iter1 != foo.end(); Iter1++){
            cout<<*Iter1<<" ";
        }

        cout<<")"<<endl;
    }   
}

int main(void)
{

    ClassFoo::NormalSort();
    return 0;
}
