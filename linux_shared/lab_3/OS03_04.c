#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = getpid();

    for (int i = 0; i < 1000; i++)
    {
        printf("%d - %d\n", i, pid);
        fflush(stdout);
        sleep(1);
    }
}
