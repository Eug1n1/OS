#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = getpid();
    char* const argv[] = { };
    
    execv("/home/eug1n1/Univer/os/linux_shared/lab_3/out/OS03_05_1", argv);

    for (int i = 0; i < 100; i++)
    {
        printf("parent: %d - %d", i, pid);
        fflush(stdout);
        sleep(1);
    }
}
