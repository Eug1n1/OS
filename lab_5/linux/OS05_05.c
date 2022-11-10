#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = getpid();
    for (int i = 1; i < 100000; i++)
    {
        printf("i: %d, pid: %d\n", i, pid);
        sleep(1);
    }

    return 0;
}

// nice -n <nice> <filename>
// renice <nice> <pid>
// fg
// bg
// jobs
