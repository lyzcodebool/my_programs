#include <iostream>
#include <thread>
#include <time.h>
#include <pthread.h>
#include <atomic>
#include <stdlib.h>

using namespace std;
//atomic_long total(0);
long total = 0;
pthread_mutex_t mutex;
void *click(void *arg)
{
    long oldtotal = *(long *)arg;
        //do{
        //}while(oldtotal == total);
        for(long i = 0; i < 1000000; ++i){
            pthread_mutex_lock(&mutex);
            total += 1;
            pthread_mutex_unlock(&mutex);
        }

    return (void *)0;
}

int main(void)
{   
    clock_t start = clock();

    pthread_t tid[100];
    for(long i = 0; i <100; i++)
    {
        int ret = pthread_create(&tid[i], NULL, click, (void *)&total);
        if(ret == -1)
            exit(1);
    }
    
    for(long j = 0; j < 100; j++){
        pthread_join(tid[j], NULL);
    }

    clock_t end = clock();
    cout<<"total :"<<total<<endl;
    cout<<"time:"<<end -start<<"ms"<<endl;

    return 0;
}
