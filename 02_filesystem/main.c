#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
    int fd;
    int num_read, num_write;
    char buf[12] = "hello world\n";

    fd = open("test.txt", O_WRONLY);
    if (fd == -1)
    {
        printf("open() failed\n");
    }

    // lseek(fd, 2, SEEK_SET);

    num_write = write(fd, buf, strlen(buf));
    if (num_write == -1)
    {
        printf("write() failed\n");
        return 0;
    }

    printf("Wrote %d byte\n", num_write);

    // struct stat file_info;
    // if (fstat(fd, &file_info) == -1)
    // {
    //     printf("fstat() failed \n");
    //     return 1;
    // }

    // printf("File type: ");
    // switch (file_info.st_mode & S_IFMT)
    // {
    // case S_IFREG:
    //     printf("Regular file\n");
    //     break;
    // case S_IFDIR:
    //     printf("Directory\n");
    //     break;
    // default:
    //     printf("Other type\n");
    //     break;
    // }

    close(fd);
    return 0;
}