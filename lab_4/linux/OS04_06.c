#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    int pid = getpid();
    
    for (int i = 0; i < 100; i++) {
        printf("i: %d, pid: %d", i, pid); 
        sleep(1);
    }

    return 0;
}
