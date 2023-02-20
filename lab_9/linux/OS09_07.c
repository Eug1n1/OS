#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int input, file_size;
    input = open("./OS09_05.txt", O_RDWR);

    char* buf;

    file_size = lseek(input, 0, SEEK_END);

    lseek(input, file_size / 2, SEEK_SET);

    buf = malloc(file_size - file_size / 2);

    read(input, buf, file_size - file_size / 2);

    printf("%s", buf);

    return 0;
}
