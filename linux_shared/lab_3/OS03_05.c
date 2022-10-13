#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    int pid;
    char* const argv[] = {};

    pid = fork();
    switch (pid) {
        case 0: {
                int exec_val = execvp("/home/eug1n1/Univer/os/linux_shared/lab_3/bin/OS03_05_1", argv);
                printf("exec: %d\n", exec_val);
            }
            break;
        case -1:
            perror("fork error");
            exit(-1);
    }

    pid = getpid();
    for (int i = 0; i < 100; i++) {
        printf("parent: %d - %d\n", i, pid);
        fflush(stdout);
        sleep(1);
    }
}
