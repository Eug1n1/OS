#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int pid = getpid();
    int size = 256 * 1024 * 1024;
    int* array = malloc(size);

    printf("pointer: %p\n", array);
    printf("pid: %d\n", pid);

    for (int i = 0; i < size / sizeof(int); i++) {
        array[i] = i;
    }

    printf("sleep\n");
    sleep(10 * 60);
    return 0;
}

