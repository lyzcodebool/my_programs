#include <iostream>
using namespace std;
//插入排序

void insert_sort(int *a, const int size)
{
    if(a == NULL || size < 0)
        return;

    int index, tmp;
    for(int i = 1; i < size; ++i)
    {
        index = i;  tmp = a[i];
        while(index > 0 && tmp < a[index-1]){
            std::swap(a[index], a[index - 1]);
            --index;
        }
    }
}

int main(void){


    return 0;
}
