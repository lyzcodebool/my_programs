#include <stdio.h>

void Merge(int *src, int *dst, int srcLength, int dstLnegth, int totalSize)
{
    if(src == NULL || dst == NULL || srcLength > totalSize || dstLnegth > totalSize || (srcLength + dstLnegth) > totalSize)
        return;
    
    int indexOrginal = srcLength;
    int newLnegth = srcLength + dstLnegth;

    while(indexOrginal >= 0 && newLnegth > indexOrginal)
    {
        /* 按照从小到大的顺序排序 */
        if(src[srcLength-1] >= dst[dstLnegth-1]){
            src[newLnegth] = dst[dstLnegth];
            --newLnegth;
            --dstLnegth;
        }else{
            src[newLnegth] = src[srcLength];
            --srcLength;
            --newLnegth;
        }
        --indexOrginal;
    }
}

int main()
{
    int A[11] = {1,3,5,7,9};
    int B[] = {2, 4, 6, 8, 0};
    Merge(A,B,5, 5, 11);
    for(int i = 0; i < 11; ++i)
    {
        printf("%3d", A[i]);
    }
    putchar(10);
    return 0;
}

