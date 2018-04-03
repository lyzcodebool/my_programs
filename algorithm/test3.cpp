#include <iostream>
#include <vector>
using namespace std;
vector<int> temp{1, 2, 3, 4, 4, 4, 4, 4, 8, 9, 0};

int vector_binarySearch(vector<int> temp, int n, int value){
    int left = 0; 
    int right = n-1;
    while(left <= right){
        int middle = left + ((left + right) >> 1);
        if(temp[middle] > value){
            right = middle -1;
        }else if(temp[middle] < value){
            left = middle + 1;
        }else{
            return middle;
        }
    }
    return -1;
}

int main(void)
{

    int n = vector_binarySearch(temp, 10, 4);
    printf("%d \n", n);

	return 0;
}
