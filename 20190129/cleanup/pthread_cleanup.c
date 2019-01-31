#include <func.h>

void cleanup(void *p)
{
   printf("I am cleanup func\n");
}

void* threadfunc(void* p)
{
    pthread_cleanup_push(cleanup,NULL);
    printf("I am child thread\n");
    sleep(5);
    pthread_cleanup_pop(0);
}

int main()
{
    pthread_t pthid;
    pthread_create(&pthid,NULL,threadfunc,NULL);
    sleep(1); 
    pthread_cancel(pthid);
    long lret;
    int ret=pthread_join(pthid,(void**)&lret);
    printf("main thread %ld,%d\n",lret,ret);
    return 0;
}

