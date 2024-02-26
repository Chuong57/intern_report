#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_producer, thread_consumer;
pthread_mutex_t my_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t my_cond = PTHREAD_COND_INITIALIZER;

#define THRESH_HOLD 10
int counter = 0;

static void *producer(void *)
{
    while(1)
    {
        pthread_mutex_lock(&my_lock);
        while(counter < THRESH_HOLD)
        {
            counter ++;
            printf("producer increased the counter's value to: %d \n", counter);
            sleep(1);
        }
        pthread_mutex_unlock(&my_lock);
    }
    pthread_exit(NULL);
}

static void *consumer(void *)
{
    while(1)
    {
        pthread_mutex_lock(&my_lock);
        if (counter == THRESH_HOLD)
        {
            printf("consumer take all counter! \n");
            counter = 0;
            printf("the number of counter after being consumed: %d\n", counter);
            sleep(3);
        }
        pthread_mutex_unlock(&my_lock);
    }
    pthread_exit(NULL);
}

int main()
{
    int ret;
    if (ret = pthread_create(&thread_producer, NULL, &producer, NULL))
    {
        printf("created thread error \n");
    }

    if (ret = pthread_create(&thread_consumer, NULL, &consumer, NULL))
    {
        printf("created thread error \n");
    }

    pthread_join(thread_producer, NULL);
    pthread_join(thread_consumer, NULL);
    
    return 0;
}