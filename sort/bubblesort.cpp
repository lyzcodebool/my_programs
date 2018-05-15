#include <iostream>
using namespace std;

//冒泡排序稳定的排序算法
//普通版本，时间复杂度n*n
void bubble_sort(int *a, const int size)
{
    if(a == NULL || size < 0)
        return;
    for(int i = 0; i < size-1; ++i){
        for(int j = 0; j < size-1-i; ++j){
            if(a[i] < a[j + 1])
                std::swap(a[j], a[j+1]);
        }
    }
}

//优化版本，最好的时间复杂度是N
void bubble_better_sort(int *a, const int size)
{
    if(a == NULL || size < 0)
        return;
    bool flag = true;
    for(int i = 0; i < size-1; ++i){
        for(int j = 0; j < size-1-i; ++j){
            if(a[i] < a[j + 1]){
                std::swap(a[j], a[j+1]);
                flag = false;
            }
        }
        if(flag)
            break;
    }
}

int main(void)
{
    
}
