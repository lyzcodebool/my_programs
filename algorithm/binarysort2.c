#include <stdio.h>

int binarySearch(int array[], int n, int value)
{
    int left = 0;
    int right  = n-1;
    while(left <= right){
        int middle = left + ((right - left) >> 1);
        if(array[middle] >= value){
            right = middle - 1;
        }else{
            left = middle + 1;
        }
    }
    return array[right + 1] > value ? right+1:-1;
}


int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    int b = binarySearch(array, 5, 5);
    printf("%d \n", b);
        

    return 0;
}
