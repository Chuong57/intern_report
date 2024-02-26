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
    int server_fd;
    socklen_t len;
    char recv_buf[BUF_SIZE];
    char send_buf[] = "Server received";

    struct sockaddr_un serv_addr;
    struct sockaddr_un clie_addr;

    ssize_t bytes;

    // Tạo socket AF_UNIX dùng để giao tiếp qua datagram (UDP)
    server_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (server_fd == -1)
    {
        handle_error("socket()");
    }

    // Khởi tạo địa chỉ server
    memset(&serv_addr, 0, sizeof(struct sockaddr_un));
    serv_addr.sun_family = AF_UNIX;
    strncpy(serv_addr.sun_path, SOCKET_PATH, sizeof(serv_addr.sun_path));

    // Gắn địa chỉ server vào socket
    if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_un)) == -1)
    {
        handle_error("bind()");
    }

    printf("Server is listening...\n");

    while(1)
    {
        len = sizeof(struct sockaddr_un);
        
        // Nhận dữ liệu từ client qua socket server_fd
        bytes = recvfrom(server_fd, recv_buf, BUF_SIZE, 0, (struct sockaddr *) &clie_addr, &len);
        if (bytes == -1)
        {
            handle_error("recv_from()");
        }

        // In ra số byte nhận được và địa chỉ của client gửi dữ liệu
        printf("Server received %ld bytes from %s \n", bytes, clie_addr.sun_path);
        printf("Data received: %s \n", recv_buf);

    
        // Gửi dữ liệu "Server received" trả lại client thông qua địa chỉ của client
        if (sendto(server_fd, send_buf, sizeof(send_buf), 0, (struct sockaddr *) &clie_addr, len) == -1)
        {
            handle_error("sendto()");
        }
    }

    return 0;
}

