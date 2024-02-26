#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>


#define BUFF_SIZE 255
#define CLIENT_NUMBER 50
#define handle_error(msg)\
    do{perror(msg); exit(EXIT_FAILURE);} while (0)


void *send_task(void *args)
{
    int new_socket_fd = *(int *)args;
    char send_buf[BUFF_SIZE];

    while(1)
    {
        int write_check;
        memset(send_buf, 0, BUFF_SIZE);
        fgets(send_buf, BUFF_SIZE, stdin);
        write_check = write(new_socket_fd, send_buf, strlen(send_buf));
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
    int new_socket_fd = *(int *)args;
    char recv_buf[BUFF_SIZE];

    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    if (getpeername(new_socket_fd, (struct sockaddr*)&client_addr, &client_addr_len) == -1)
    {
        handle_error("getpeername()");
    }

    char *client_ip = inet_ntoa(client_addr.sin_addr);
    while(1)
    {
        int read_check;
        memset(recv_buf, 0, BUFF_SIZE);
        read_check = read(new_socket_fd, recv_buf, sizeof(recv_buf));
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
        printf("message from client %s: %s\n",client_ip, recv_buf);
    }
    close(new_socket_fd);
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
    int server_fd;
    int option;
    int new_socket_fd;
    int client_addr_len;
    struct sockaddr_in server_addr, client_addr;


    if (argc < 2)
    {
        printf("Wrong format \nSample command: ./server_multi <port>\n");   
        exit(EXIT_FAILURE);
    }
    else{
        port = atoi(argv[1]);
    }

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    memset(&client_addr, 0, sizeof(struct sockaddr_in));


    //step 1: create socket.
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        handle_error("socket()");
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1)
    {
        handle_error("setsockopt()");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    //step2: binding
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        handle_error("bind()");
    }

    //step3: listening
    if (listen(server_fd, CLIENT_NUMBER) == -1)
    {
        handle_error("listen()");
    }

    client_addr_len = sizeof(client_addr);
    while(1)
    {
        printf("Server is listening at port: %d\n", port);

        //step4: accept
        new_socket_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
        if (new_socket_fd == -1)
        {
            handle_error("accept()");
        }
        system("clear");
        printf("Got connection to client\n");

        pid_t pid = fork();
        if (pid == -1)
        {
            handle_error("fork()");
        }
        else if (pid == 0) //child
        {
            close(server_fd);
            start_chat(new_socket_fd);
            exit(EXIT_SUCCESS);
        }
        else{
            close(new_socket_fd);
        }
    }
    close(server_fd);
    return 0;
}