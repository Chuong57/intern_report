#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 5

int shared_resource = 0;
sem_t semaphore;

void* thread_function(void* thread_id) {
    int tid = *(int*)thread_id;
    
    sem_wait(&semaphore);

    shared_resource += 1;
    printf("Thread %d accessed shared resource. New value: %d\n", tid, shared_resource);
    sem_post(&semaphore);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    int i;

    sem_init(&semaphore, 0, MAX_THREADS);

    for (i = 0; i < MAX_THREADS; i++) 
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) 
    {
        pthread_join(threads[i], NULL);
    }
    
    sem_destroy(&semaphore);

    return 0;
}
