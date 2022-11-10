#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/resource.h>
#include <sched.h>
#include <sys/wait.h>

void long_loop(char* name)
{
    for (int i = 0; i < 10000; i++)
    {
        printf("%s\ti: %d,\tpid: %d\n", name, i,getpid());
        sleep(1);
    }
}

int main(int argc, char **argv)
{
    pid_t pid;
    switch (pid = fork())
    {
        case -1:
            perror("fork error");
            return -1;
        case 0:
            setpriority(PRIO_PROCESS, 0, -10);
            long_loop("child");
            break;
        default:
            long_loop("parent");
    }
}

// sudo
