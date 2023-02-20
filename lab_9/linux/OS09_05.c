#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("./OS09_05.txt", "r");
    int lines = 0;

    if (fp == NULL) {
        return -1;
    }

    while (fscanf(fp, "%*[^\n]") != EOF && fscanf(fp, "%*c") != EOF ) {
        lines++;
    }

    printf("lines: %i\n", lines);

    return 0;
}
