#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = getpid();
    char* const argv[] = { };
    
    execv("./out/OS03_05_1", argv);

    for (int i = 0; i < 100; i++)
    {
        printf("parent: %d - %d", i, pid);
        sleep(1);
    }
}