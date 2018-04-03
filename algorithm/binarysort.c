#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;
    while(left <= right){
        int middle = left+((right - left) >> 1);
        if(array[middle] > value){
            right = middle -1;
        }
        else if(array[middle] < value)
            left = middle + 1;
        else
            return middle;
    }
    return -1;
}

int main(void)
{
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int b = BinarySearch(a, 7, 6);
    printf("%d \n", b);
}
