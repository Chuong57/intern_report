#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle_sigchld(int signum)
{
    int status;
    pid_t pid;

    // Xử lý tất cả các tiến trình con đã kết thúc
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        // In ra thông tin về tiến trình con đã kết thúc
        if (WIFEXITED(status))
        {
            printf("Child process with PID %d exited with status %d\n", pid, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Child process with PID %d terminated by signal %d\n", pid, WTERMSIG(status));
        }
    }
}

int main()
{
    // Đăng ký xử lý tín hiệu SIGCHLD
    signal(SIGCHLD, handle_sigchld);

    pid_t child_pid = fork();

    if (child_pid == 0)
    {
        // Child process
        printf("Child process with PID %d is running\n", getpid());
        sleep(2);
        printf("Child process with PID %d is exiting\n", getpid());
        return 123;
    }
    else if (child_pid > 0)
    {
        // Parent process
        printf("Parent process with PID %d is running\n", getpid());
        while (1);
    }
    else
    {
        // Fork failed
        printf("Fork failed\n");
        return 1;
    }

    return 0;
}