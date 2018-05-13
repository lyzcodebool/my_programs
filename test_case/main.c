#include "lib_acl.h"
#include <stdio.h>  
#include <stdlib.h>  
  
static void fifo_test(void)  
{  
    ACL_FIFO *fifo;  
    int   i;  
    char *ptr;  
    ACL_ITER iter;  
  
    fifo = acl_fifo_new();  // 创建队列  
  
    for (i = 0; i < 20; i++) {  
        ptr = (char*) acl_mymalloc(100);  
        snprintf(ptr, 100, "test:%d", i);  
        acl_fifo_push(fifo, ptr);  // 向队列中添加动态元素  
    }  
  
    // 遍历队列中的所有元素  
    acl_foreach(iter, fifo) {  
            const char *ptr = (const char*) iter.data;  
            printf(">>>%s\n", ptr);  
    }  
  
    while (1) {  
        ptr = (char*) acl_fifo_pop(fifo);  // 从队列中取得动态元素  
        if (ptr == NULL)  
            break;  
        printf("fifo pop: %s\n", ptr);  
    }  
  
    acl_fifo_free(fifo, acl_myfree_fn);  // 释放队列  
}  
  
int main(int argc acl_unused, char *argv[] acl_unused)  
{  
    fifo_test();  
    getchar();  
    return (0);  
}
