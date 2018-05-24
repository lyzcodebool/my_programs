#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <jemalloc/jemalloc.h>
#include <time.h>

typedef struct version
{
    long total;
    long  version;
}version;

version a = {0, 0};
pthread_mutex_t mutex;
void *func_1(void *arg)
{
    long count = *(long *)arg;
    if(a.version != count)
        return (void *)0;
    for(int j = 0; j  <1000000; j++)
    {
        a.total += 1;
    }
    return (void*)0;
}
int main()
{
    int i;

    clock_t start = clock();
    pthread_t  tid[100];
    for(i = 0; i < 100; ++i)
    {
        int ret = pthread_create(&tid[i], NULL,  func_1, (void *)&a.version);
        if(ret == -1){
            perror("thread");
        }
    }

    clock_t end = clock();
    for(int j = 0; j < 100; j++)
        pthread_join(tid[j], NULL);

    printf("\n%ld \n", a.total);
    printf("time: %ld\n", end - start);

}
