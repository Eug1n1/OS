#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    int pid;
    char* const argv[] = {};

    switch (pid = fork()) {
        case 0:
            execv("./out/OS03_05_1", argv);
            break;
        case -1:
            perror("fork error");
            exit(-1);
    }

    pid = getpid();
    for (int i = 0; i < 100; i++) {
        printf("parent: %d - %d", i, pid);
        sleep(1);
    }
}