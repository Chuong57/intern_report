#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid;

    char *child_argv[] = {"/bin/ls", NULL};
    char string[] = "-l";

    pid = fork();

    if (pid == 0)
    {
        printf("I'm child\n");
        execv("/bin/ls", child_argv);
    }

    else{
        printf ("I'm parent\n");
    }

    return 0;
}