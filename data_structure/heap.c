#include <stdio.h>
#include <stdlib.h>

typedef enum{
    FALSE,
    TRUE
}BOOL;

typedef struct{
    int *entryArray; //用于指向对内存的数组指针
    int arrayLen;   //保存数组的最大长度
    int heapLen;    //保存堆长度
}*Heap_t;
//二叉堆初始化
void initHeapEntry(Heap_t heap, int len)
{
    heap->entryArray = (int *)malloc(sizeof(int)*len);
    if(heap->entryArray == NULL){
        printf("malloc error\n");
        exit(1);
    }
    heap->arrayLen = len;
    heap->heapLen = 0;
}

//二叉堆判空/清空
BOOL isEmptyHeap(Heap_t heap)
{
    if(heap->arrayLen == 0)
        return TRUE;
    return FALSE;
}

void cleanHea(Heap_t heap)
{
    if(heap != NULL)
    {
        free(heap->entryArray);
        heap->arrayLen = 0;
        heap->heapLen = 0;
    }
}
//元素插入，向上调整法,这里是最小堆
void insertHeap(Heap_t heap, int ele)
{
    //如果堆满，将堆数组长度扩展到原来的两倍
    if(heap->heapLen == heap->arrayLen){
        heap->entryArray = (int *)realloc(heap, sizeof(int)*2*heap->arrayLen);
        heap->arrayLen = 2*heap->arrayLen;
    }

    //对尾添加新元素
    heap->entryArray[heap->heapLen] = ele;
    heap->heapLen ++;
    int i = heap->heapLen-1;  //i指向待调整元素的位置
    /*最小堆向上调整算法*/
    while(i != 0){
        int j = (i - 1) / 2;
        if(ele >= heap->entryArray[j])  //如果新加入的元素大于父节点，跳出循环
            break;
        heap->entryArray[i] = heap->entryArray[j];
        i = j;
    }
    heap->entryArray[i] = ele;
}

//二叉堆的删除
void deleteHeapTop(Heap_t heap)
{
    if(heap->heapLen == 0){
        printf("heap empty\n");
        exit(0); //正常运行程序退出  exit(1):异常终止
    }
    int temp = heap->entryArray[0];  //取出堆顶元素
    heap->heapLen --;
    if(heap->heapLen == 0)
        exit(1);
    int lastData = heap->entryArray[heap->heapLen];  //删除了一个元素，最后一个元素的位置需要调整
    int i = 0; 
    int j = 2*i + 1;  //j指向i的左孩子的位置

    //最小堆的向下调整算法
    while(j <= heap->heapLen - 1){
        if(j < heap->heapLen && heap->entryArray[j] > heap->entryArray[j + 1])
            j++;
        if(lastData < heap->entryArray[j]) //最后一个元素小于孩子节点，那莫位置找到了
            break;
        heap->entryArray[i] = heap->entryArray[j]; //将孩子元素放到父节点的位置
        i = j;
        j = 2*i + 1;
    }
    heap->entryArray[i] = lastData;
}

//二叉堆删除指定的元素
//查找指定元素的位置
int GetIndex(Heap_t heap, int ele)
{
    for(int i = 0; i < heap->heapLen; ++i){
        if(heap->entryArray[i] == ele)
            return i;
    }
    return -1;
}

//元素删除函数
BOOL removeHeadEle(Heap_t heap, int ele)
{
    int index;
    if(heap->heapLen == 0)
        return FALSE;
    index = GetIndex(heap, ele);
    if(index == -1)
        return FALSE;
    int temp = heap->entryArray[index]; //记录要删除的元素
    int lastdata = heap->entryArray[heap->heapLen-1];
    heap->heapLen --;
    int i = index;
    int j = 2<<1|1;
    //最小堆的向下调整算法
    while(j <= heap->heapLen-1)
    {
        if(j < heap->heapLen && heap->entryArray[j] > heap->entryArray[j + 1])
            j ++;
        if(lastdata < heap->entryArray[j])
            break;
        heap->entryArray[i] = heap->entryArray[j];
        i = j;
        j = 2*i+1;
    }
    heap->entryArray[i] = lastdata;
    return FALSE;
}




