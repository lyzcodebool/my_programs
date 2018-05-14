#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
//读写锁相互阻塞
//读得时候不可以写，写的时候不可以读

static struct Info{
    int data;
    const char *name;
}info = {10, "name"};

pthread_rwlock_t rwmutex; 

void *rd_lock(void *arg)
{
    sleep(5);
    printf("start read....\n");
    pthread_rwlock_rdlock(&rwmutex);
    printf("get read lock\n");
    printf("%d  %s\n", info.data, info.name);

    sleep(10);
    printf("%ld read unlock\n", pthread_self());
    pthread_rwlock_unlock(&rwmutex);

    return (void *)0;
}

void *wr_lock(void *arg)
{
    printf("wait read lock...\n");
    pthread_rwlock_wrlock(&rwmutex);
    printf("read unlock and get write lock\n");
    info.data = 20;
    info.name = "lyz";
    sleep(3);
    printf("%ld write unlock\n", pthread_self());
    pthread_rwlock_unlock(&rwmutex);
    return (void *)0;
}

int main(void)
{
    pthread_t tid1[3];
    pthread_t tid2[3];
    for(int i = 0; i < 3; ++i)
    {
        int ret1 = pthread_create(&tid1[i], NULL, rd_lock, NULL);
        if(ret1 == -1)
            perror("read pthread");
    }
    for(int i = 0; i< 3; ++i){
        int ret2 = pthread_create(&tid2[i], NULL, wr_lock, NULL);
        if(ret2 == -1)
            perror("write pthread");
    }

    for(int i = 0; i < 3; ++i)
        pthread_join(tid1[i], NULL);
    for(int i = 0; i < 3; ++i)
        pthread_join(tid2[i], NULL);

    return 0;
}
