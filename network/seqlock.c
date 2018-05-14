#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_rwlock_t mutex;

typedef struct seqlock{
    pthread_rwlock_t mutex;
    int sequence;
}seqlock_t;

static struct stuInfo{
    const char *name;
    int age;
}stuInfo = {"xiaoming", 10};

void seq_wrlock(seqlock_t *sl)
{
    pthread_rwlock_wrlock(&sl->mutex);
    ++sl->sequence;
}
void seq_wrunlock(seqlock_t *sl)
{
    ++sl->sequence;
    pthread_rwlock_unlock(&sl->mutex);
}

unsigned read_begin(seqlock_t *sl)
{
    unsigned ret;
foo:
    printf("%ld read begin...\n", pthread_self());
    ret = sl->sequence;
    if(ret/2 != 0){
        goto foo;
    }
    return ret;
}

int seqreadtry(const seqlock_t *sl, unsigned seq){
    return ((unsigned)sl->sequence != seq);
}

void *read_info(void *arg)
{
    int seq = 0;
    seqlock_t sl = *(seqlock_t *)arg;
    do{
        seq = read_begin(&sl);
        printf("name: %s |**|  age: %d\n", stuInfo.name, stuInfo.age);
    }while(seqreadtry(&sl, seq));

    return (void *)0;
}

void *write_info(void *arg)
{
    seqlock_t sl = *(seqlock_t *)arg;
    seq_wrlock(&sl);
    
    printf("%ld start write ...\n", pthread_self());
    stuInfo.age += 1;
    printf("%ld write unlock...\n", pthread_self());

    seq_wrunlock(&sl);
    return (void *)0;
}

int main(void)
{
    pthread_t tid1[100];
    pthread_t tid2[100];

    seqlock_t sl = {mutex, 0};
    for(int i = 0; i < 100; ++i)
    {
        pthread_create(&tid1[i], NULL, write_info, (void *)&sl);
        pthread_create(&tid2[i], NULL, read_info, (void *)&sl);
    }

    for(int i = 0; i < 100; ++i)
    {
        pthread_join(tid1[i], NULL);
    }
    for(int i = 0; i < 100; ++i)
    {
        pthread_join(tid2[i], NULL);
    }

    pthread_rwlock_destroy(&mutex);
    return 0;
}
