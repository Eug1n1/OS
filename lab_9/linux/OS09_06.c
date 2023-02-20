#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("no argument specified");
        return 1;
    }

    FILE *input, *out;
    input = fopen("./OS09_05.txt", "r");
    if (input == NULL) {
        printf("error while openning input file");
        return 1;
    }

    char* line = NULL;
    size_t len = 0;

    int param = strtol(argv[1], NULL, 10);
    int is_not_even = param % 2;

    if (is_not_even == 0) {
        out = fopen("./OS09_06_2.txt", "w");
    } else {
        out = fopen("./OS09_06_1.txt", "w");
    }

    if (out == NULL) {
        printf("error while openning out file");
        return 1;
    }

    for (int i = 0; getline(&line, &len, input) != -1 ; i++) {
        if (i % 2 == is_not_even) {
            fprintf(out, "%i: %s", i, line);
        }    
    }

    return 0;
}
