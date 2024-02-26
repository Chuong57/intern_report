#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

pthread_t thread_id1, thread_id2;

typedef struct data
{
    char name[30];
    char msg[30];
} data_t;

static void *thr_handle(void *args)                     
{
    pthread_t tid = pthread_self();
    data_t *data = (data_t *)args;

    if (pthread_equal(tid, thread_id1))
    {
        printf ("I'm thread_id1 \n");
    }
    else{
        printf("I'm thread_id2\n");
        printf("Hello %s, welcome to join %s \n", data->name, data->msg);
    }
}

static void *thr_handle1(void *args)                  //con tro ham 
{
    printf ("I'm thread handle 1 \n");
}

static void *thr_handle2(void *args)
{
    printf ("I'm thread handle 2 \n");
}

int main(int argc, char const *argv[])
{
    int ret;
    data_t data = {0};
    strncpy(data.name, "Hoang Chuong", sizeof(data.name));
    strncpy(data.msg, "Thread programming demo", sizeof(data.msg));\

    if (ret = pthread_create(&thread_id1, NULL, thr_handle1, NULL))
    {
        printf("pthread_create() error number = %d\n" , ret);
        return -1;
    }

    sleep(2);

    if (ret = pthread_create(&thread_id2, NULL, &thr_handle2, &data))
    {
        printf("pthread_create() error number = %d\n", ret);
        return -1;
    }

    sleep(5);

    return 0;
}

