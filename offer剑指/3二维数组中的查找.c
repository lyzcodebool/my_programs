#include <stdio.h>
//行递增，列递增

typedef enum _BOOL{
    TURE = 1,
    FALSE
}_BOOL;

_BOOL Find(int *matrix, int rows, int columns, int number)
{
    _BOOL found = FALSE;
    if(matrix != NULL && rows > 0 && columns > 0){
        int row = 0;
        int column = columns-1;
        while(row < rows && column >= 0){
            if(matrix[row * columns + columns] == number){
                found = TURE;
                break;
            }else if(matrix[row * columns + column] > number){
                --column;
            }else
                ++row;
        }
    }
    return found;
}

int main()
{
    return 0;
}

