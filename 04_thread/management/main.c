#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

pthread_t thread_id1, thread_id2, thread_id3;

static void *thread_handler1(void *args)
{
    printf("thread id 1 is created successfully \n");
    pthread_exit(&thread_id1);
    printf("thread id 1 exit \n");
}

static void *thread_handler2(void *args)
{
    printf("thread id 2 is created successfully \n");
    while(1)
    {
        printf("thread id 2 write something \n");
        sleep(1);
    }
}

static void *thread_handler3(void *args)
{
    pthread_detach(pthread_self());
    pthread_exit(NULL);
}


int main()
{
    int ret;
    int counter = 0;

    // if (ret = pthread_create(&thread_id1, NULL, &thread_handler1, NULL))
    // {
    //     printf("thread id 1 created error \n");
    //     return -1;
    // }

    // if (ret = pthread_create(&thread_id2, NULL, &thread_handler2, NULL))
    // {
    //     printf("thread id 2 created error\n");
    //     return -1;
    // }

    while(1)
    {
        if (ret = pthread_create(&thread_id3, NULL, &thread_handler3, NULL))
        {
            printf("pthread_create() error number %d\n", ret);
            break;
        }

        counter ++;

        if (counter % 1000 == 0)
        {
            printf("thread created: %d\n", counter);
        }
    }

    sleep(5);
    // pthread_join(thread_id1, NULL);
    // pthread_cancel(thread_id2);

    return 0;
}