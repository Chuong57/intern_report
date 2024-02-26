#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_id1, thread_id2;
pthread_mutex_t my_lock = PTHREAD_MUTEX_INITIALIZER;
int shared_resource = 0;


static void *thread_handle1(void* args) 
{
    pthread_mutex_lock(&my_lock);
    (*(int*)args) += 1;
    printf("Thread 1 changed the shared resource to: %d\n", (*(int*)args));
    pthread_mutex_unlock(&my_lock);
    pthread_exit(NULL);
}

static void *thread_handle2(void* args)
{   
    pthread_mutex_lock(&my_lock);
    printf("The value of shared resource before being changed by thread 2: %d\n", shared_resource);
    printf("Thread 2 changed the shared resource to: %d\n", ++shared_resource);
    pthread_mutex_unlock(&my_lock);
    pthread_exit(NULL);
}

int main()
{
    int ret;
    if (ret = pthread_create(&thread_id1, NULL, thread_handle1, &shared_resource))
    {
        printf("thread 1 created fail \n");
        return -1;
    }

    if (ret = pthread_create(&thread_id2, NULL, &thread_handle2, NULL))
    {
        printf("thread 2 created fail \n");
        return -1;
    }

    sleep(3);
    return 0;
}