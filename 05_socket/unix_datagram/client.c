#include <stdio.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>

#define BUF_SIZE 128
#define SOCKET_PATH "./socket_datagram"

void handle_error(const char* msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[])
{
    int client_fd;
    socklen_t len;
    char recv_buf[BUF_SIZE];

    struct sockaddr_un serv_addr;
    ssize_t bytes;
    size_t msglen;

    // Tạo socket AF_UNIX dùng để giao tiếp qua datagram (UDP)
    client_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (client_fd == -1)
    {
        handle_error("socket()");
    }

    // Khởi tạo địa chỉ server
    memset(&serv_addr, 0, sizeof(struct sockaddr_un));
    serv_addr.sun_family = AF_UNIX;
    strncpy(serv_addr.sun_path, SOCKET_PATH, sizeof(serv_addr.sun_path));

    int optval = 1;
    setsockopt(client_fd, SOL_SOCKET, SO_PASSCRED, &optval, sizeof(serv_addr.sun_path));

    msglen = strlen(argv[1]);
    

    // Gửi dữ liệu 
    if (sendto(client_fd, argv[1], msglen, 0, (struct sockaddr *) &serv_addr, sizeof(struct sockaddr_un)) == -1)
    {
        handle_error("sendto()");
    }

    bytes = recvfrom(client_fd, recv_buf, BUF_SIZE, 0, (struct sockaddr *) &serv_addr, &len);
    if (bytes == -1)
    {
        handle_error("recv_from()");
    }
    printf("%s\n", recv_buf);

    return 0;
}

