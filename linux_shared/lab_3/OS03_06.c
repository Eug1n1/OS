#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid = getpid();

    system("./out/OS03_05_1");

    for (int i = 0; i < 100; i++)
    {
        printf("parent: %d - %d", i, pid);
        sleep(1);
    }
}