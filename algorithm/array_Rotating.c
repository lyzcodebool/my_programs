#include <stdio.h>
#include <stdlib.h>
//旋转数组的最小元素

int MinInRouting(int *array, int length)
{
    if(array == NULL || length <= 0){
        printf("error array\n");
        exit(1);
    }
    int index1 = 0; 
    int index2 = length - 1;
    int minIndex = index1;

    while(index1 < index2){
        if(index2 - 1 == index1){
            minIndex = index2;
            break;
        }

        minIndex = (index1 + index2)/2;
        if(array[index1] < array[minIndex])
            index1 = minIndex;
        if(array[index2] > array[minIndex])
            index2 = minIndex;
    }
    return array[minIndex];
}

int main(void)
{
    

    return 0;
}
