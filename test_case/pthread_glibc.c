#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *thread_task(void *arg){
    
//    int a[1024] = {0};
 //   a[1] = 10;
    return (void *)0;
}

int main(void)
{
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, thread_task, (void *)NULL);
    if(ret < 0){
        perror("pthread_create");
        exit(0);
    }
    while(1){}
    pthread_join(tid, NULL);
}
