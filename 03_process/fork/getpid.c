#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid = 0;

    pid = fork();
    if (pid == 0)
    {
        printf("I'm a child, my pid is %d\n", getpid());
        printf("Child process will be terminated in 20s\n");
        sleep(20);
        return 5;
    }
    else if (pid > 0)
    {
        printf("I'm parent process, my pid is %d\n", getpid());
        int status = 0;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            printf("child process is terminated normally!\n");
        }
        else
        {
            printf("child process is terminated abnormally! \n");
        }
    }
    else
    {
        printf("Fork failed! \n");
    }

    return 0;
}

