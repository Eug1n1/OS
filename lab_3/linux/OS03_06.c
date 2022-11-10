#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid = getpid();

    system("/home/eug1n1/Univer/os/linux_shared/lab_3/out/OS03_05_1");

    for (int i = 0; i < 100; i++)
    {
        printf("parent: %d - %d\n", i, pid);
        fflush(stdout);
        sleep(1);
    }
}
