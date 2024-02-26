#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_CHILDREN 2

int shared_resource = 0;
sem_t *semaphore; // Change to pointer for shared memory semaphore

void child_process(int process_id)
{
    sem_wait(semaphore);
    shared_resource++;

    printf("Child process %d accessed shared resource. New value: %d\n", process_id, shared_resource);

    sem_post(semaphore);
    exit(0);
}

int main()
{
    pid_t pid;

    // Create a shared semaphore
    semaphore = sem_open("/shared_semaphore", O_CREAT, 0644, 1); // Initial value: 1
    if (semaphore == SEM_FAILED)
    {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            child_process(i + 1);
        }
    }

    // Wait for all child processes to terminate
    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        wait(NULL);
    }

    // Unlink the semaphore
    sem_unlink("/shared_semaphore");

    return 0;
}
