#include <stdio.h>
#include <stdlib.h>

typedef char bool;
#define true 1
#define false 0
//二维数组判断元素是否存在

bool find_num(int *matrix, int rows, int columns, int number)
{
    bool founded = false;
    //测试用例
    if(matrix != NULL && rows > 0 && columns > 0){
        int row = 0;
        int column = columns-1;
        while(row < rows && column >= 0){
            if(matrix[row * columns + column] == number){
                founded = true;
                break;
            }else if(matrix[row * columns + column] > number){
                --column;
            }else{
                ++row;
            }
        }
    }
    return founded;
}

void printArr(int a[][4], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", a[i][j]);
        }
        putchar(10);
    }
}

int main(void)
{
    int array[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};   
    //int *p = array[0];
    printArr(array, 4, 4);
    
    bool n = find_num(array[0], 4, 4, 7);
    if(n == true)
        printf("find!\n");
    else
        printf("not find!\n");
    return 0;
}
