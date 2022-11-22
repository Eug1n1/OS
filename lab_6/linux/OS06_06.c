#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {

    int pid = getpid();

    for (int i = 0; i < 10000; i++) {
        printf("i: %d\tpid: %d\n", i, pid);
        sleep(1);
    }

    return 0;
}
