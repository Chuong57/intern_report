#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFF_SIZE 256
#define handle_error(msg)\
    do {perror(msg); exit(EXIT_FAILURE);} while(0)

void *send_task(void *args)
{
    int client_fd = *(int *)args;
    char send_buf[BUFF_SIZE];
    
    while(1)
    {

        int write_check;
        memset(send_buf, 0, BUFF_SIZE);

        fgets(send_buf, BUFF_SIZE, stdin);
        write_check = write(client_fd, send_buf, strlen(send_buf));
        if (write_check == -1)
        {
            handle_error("write()");
        }
        if (strncmp("stop", send_buf, 4) == 0)
        {
            system("clear");
            break;
        }
    }
    return NULL;
}

void *recv_task(void *args)
{
    int client_fd = *(int *)args;
    char recv_buf[BUFF_SIZE];
    while(1)
    {
        int read_check;
        memset(recv_buf, 0, BUFF_SIZE);
        read_check = read(client_fd, recv_buf, sizeof(recv_buf));
        // printf("r %d\n", read_check);
        if (read_check == -1)
        {
            handle_error("read()");
        }
        
        if (strncmp("stop", recv_buf, 4) == 0)
        {
            system("clear");
            break;
        }
        printf("message from server: %s\n", recv_buf);
    }
    close(client_fd);
    return NULL;
}

void start_chat(int new_socket_fd)
{
    pthread_t send_thread, receive_thread;
    int ret;

    if (ret = pthread_create(&send_thread, NULL, send_task, &new_socket_fd))
    {
        handle_error("thread_create(send)");
    }
    if (ret = pthread_create(&receive_thread, NULL, recv_task, &new_socket_fd))
    {
        handle_error("thread_create(recv)");
    }

    pthread_join(send_thread, NULL);
    pthread_join(receive_thread, NULL);

}

int main(int argc, char *argv[])
{
    int port;
    int client_fd;
    struct sockaddr_in client_addr;

    memset(&client_addr, 0, sizeof(client_addr));

    if (argc < 3)
    {
        printf("wrong command...\nsample command: ./client <server addr> <port>\n");
    }
    port = atoi(argv[2]);

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, argv[1], &client_addr.sin_addr) == -1)
    {
        handle_error("inet_pton()");
    }

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        handle_error("socket()");
    }

    if (connect(client_fd, (struct sockaddr *)&client_addr, sizeof(client_addr)) == -1)
    {
        handle_error("connect()");
    }

    printf("Got connection\n");

    start_chat(client_fd);

    return 0;
}