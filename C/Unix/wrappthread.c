//#include "unp.h"
#include "pthread.h"
#include "errno.h"

void Pthread_mutext_lock(pthread_mutex_t* mptr)
{
    int n;
    if((n = pthread_mutex_lock(mptr)) > 0)
    {
        return;
    }
    errno = n;
    err_sys("pthreadd_mutex_lock error");
}