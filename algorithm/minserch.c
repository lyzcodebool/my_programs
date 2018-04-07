#include <stdio.h>

int minsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n-1;
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if(x < v[mid]){
            high = mid-1;
        }else if(x > v[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
    }

    return -1;
}

int main()
{
    int array[] = {1, 3, 4, 5, 6, 7, 8, 9};
    int result, num;

    num = sizeof(array)/sizeof(int);
    
    result = minsearch(8, array, num);
    
    if(result != -1){
        printf("finded! = %d\n", result);
    }else{
        printf("no this num\n");
    }


    return 0;
}
