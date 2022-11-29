#include <bits/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    struct timespec cpu_timespec, start_timespec, end_timespec;

    clock_gettime(CLOCK_REALTIME, &start_timespec);

    for (unsigned long i = 0;; i++) {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_timespec);

        if (cpu_timespec.tv_sec == 2) {
            printf("i: %lu\n", i);
            break;
        }
    }

    clock_gettime(CLOCK_REALTIME, &end_timespec);

    printf(
            "real time: %ld.%ld\n",
            end_timespec.tv_sec - start_timespec.tv_sec,
            labs(end_timespec.tv_nsec - start_timespec.tv_nsec)
        );
}
