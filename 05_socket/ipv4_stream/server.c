#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define CLIENT_NUM 50
#define BUFF_SIZE 256
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE);} while (0)

void start_chat(int new_socket_fd)
{
    int num_read, num_write;
    char send_buff[BUFF_SIZE];
    char recv_buff[BUFF_SIZE];
    while(1)
    {
        memset(send_buff, '0', sizeof(send_buff));
        memset(recv_buff, '0', BUFF_SIZE);

        num_read = read(new_socket_fd, recv_buff, BUFF_SIZE);
        if(num_read == -1)
        {
            handle_error("read()");
        }

        if (strncmp("stop", recv_buff, 4) == 0)
        {
            system("clear");
            break;
        }
        
        printf("Message from client: %s\n", recv_buff);

        printf("Reply: ");
        fgets(send_buff, BUFF_SIZE, stdin);
        write(new_socket_fd, send_buff, sizeof(send_buff));
        if (strncmp("stop", recv_buff, 4) == 0)
        {
            system("clear");
            break;
        }
    }
    close(new_socket_fd);
}


int main(int argc, char *argv[])
{
    int port;
    int option;
    int cli_addr_len;
    int server_fd, new_socket_fd;

    struct sockaddr_in server_addr, client_addr;

    if (argc < 2)
    {
        printf ("No port provided \nSample command: ./server <port number>\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        port = atoi(argv[1]);
    }

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    memset(&client_addr, 0, sizeof(struct sockaddr_in));

    //create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        printf("create socket failed\n");
    }

    //avoid address already in use
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1)
    {
        handle_error("setsockopt()");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        handle_error("bind()");
    }

    if (listen(server_fd, CLIENT_NUM) == -1)
    {
        handle_error("listen()");
    }

    cli_addr_len = sizeof(client_addr);

    while(1)
    {
        printf("Server is listening at port: %d \n...\n", port);
        new_socket_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&cli_addr_len);
        if (new_socket_fd == -1)
        {
            handle_error("accept()");
        }

        system("clear");

        printf("Server: got connection \n");
        start_chat(new_socket_fd);
    }

    close(server_fd);
    return 0;
}