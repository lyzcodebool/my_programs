#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;
int main()
{
    int array[] = {0, 2, 3, 4 , 5, 6, 6, 6, 7, 8};
    vector<int> foo1(array, array+sizeof(array)/sizeof(int));
    int array1[] = {6, 6};
    vector<int> foo2(array1, array1+sizeof(array1)/sizeof(int));
    int array2[] = {5, 6};
    vector<int> foo3(array2, array2+sizeof(array2)/sizeof(int));
    int array3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> foo4(array3, array3+sizeof(array3)/sizeof(int));
    

    //找出foo1之中相邻元素值相等的第一个元素
    cout<<*adjacent_find(foo1.begin(), foo1.end())<<endl;

    //找出foo1中元素值为6的元素
    cout<<count(foo1.begin(), foo1.end(), 6)<<endl;

    //找出foo1之中小于7的元素个数
    cout<<count_if(foo1.begin(), foo1.end(), bind2nd(less<int>(), 7))<<endl;

    //找出foo1之中大于2的第一个元素所在的位置
    cout<<*find_if(foo1.begin(), foo1.end(), bind2nd(greater<int>(), 2))<<endl;

    //找出foo1之中字序列foo2所出现的最后一个位置，再往后3个位置的元素
    cout<<*(find_end(foo1.begin(), foo1.end(), foo2.begin(), foo2.end()) + 3)<<endl;
     

}
