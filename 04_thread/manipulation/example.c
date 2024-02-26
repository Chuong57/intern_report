#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>

pthread_t thread_01, thread_02, thread_03;

static void *thread_handle1(void *args)
{
    int fd;
    int num_write;
    
    fd = open("test.txt", O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        printf("open file failed\n");
    }

    // Position file pointer for thread 1
    lseek(fd, 0, SEEK_SET);

    for (int i = 0; i < 500000; i++)
    {
        num_write = write(fd, args, 1);
        if (num_write == -1)
        {
            printf("write failed\n");
        }
    }

    printf("finished by thread 1 \n");
    close(fd);
}

static void *thread_handle2(void *args)
{
    int fd;
    int num_write;
    
    fd = open("test.txt", O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        printf("open file failed\n");
    }

    // Position file pointer for thread 2
    lseek(fd, 500000, SEEK_SET);

    for (int i = 0; i < 500000; i++)
    {
        num_write = write(fd, args, 1);
        if (num_write == -1)
        {
            printf("write failed\n");
        }
    }

    printf("finished by thread 2\n");
    close(fd);
}

static void *thread_main(void *args)
{
    int fd;
    int num_write;
    
    fd = open("test.txt", O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        printf("open file failed\n");
    }

    lseek(fd, 0, SEEK_SET);
    for (int i = 0; i < 1000000; i++)
    {
        num_write = write(fd, args, 1);
        if (num_write == -1)
        {
            printf("write failed\n");
        }
    }

    printf("finished by main thread\n");
    close(fd);
}

int main()
{
    char data[1] = "A";
    int ret;
    
    if (ret = pthread_create(&thread_01, NULL, &thread_handle1, &data))
    {
        printf("create thread 01 failed \n");
    }

    if (ret = pthread_create(&thread_02, NULL, &thread_handle2, &data))
    {
        printf("create thread 02 failed \n");
    }

    if (ret = pthread_create(&thread_03, NULL, &thread_main, &data))
    {
        printf("create thread main failed \n");
    }

    pthread_join(thread_01, NULL);
    pthread_join(thread_02, NULL); 
    pthread_join(thread_03, NULL);

    return 0;
}
