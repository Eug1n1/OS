#include <bits/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    struct timespec cpu_timespec, start_timespec, end_timespec;
    long int raw_start, raw_end;

    clock_gettime(CLOCK_REALTIME, &start_timespec);

    for (unsigned long i = 0;; i++) {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_timespec);

        if (cpu_timespec.tv_sec == 2) {
            printf("i: %lu\n", i);
            break;
        }
    }

    clock_gettime(CLOCK_REALTIME, &end_timespec);

    raw_start = start_timespec.tv_sec * 1000000000 + start_timespec.tv_nsec;
    raw_end = end_timespec.tv_sec * 1000000000 + end_timespec.tv_nsec;

    printf(
            "real time: %ld ns\n",
            labs(raw_start - raw_end)
        );
}
