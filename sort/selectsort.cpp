#include <iostream>
//选择排序
//
//非稳定的排序算法
void select_sort(int *a, const int size)
{
    if(a == NULL || size < 0)
        return;
    for(int i = 0; i < size; ++i){
        int minIndx = i;
        for(int j = i+1; j < size; ++j){
            if(a[j] < a[minIndx])
                minIndx = j;
        }
        if(minIndx != i)
            std::swap(a[minIndx], a[i]);
    }
}

int main(void)
{

    return 0;
}
