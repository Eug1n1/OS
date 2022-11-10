#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <unistd.h>

#define gettid() syscall(SYS_gettid)

int main(int argc, char *argv[]) {
    int pid = getpid();
    int tid = gettid();
    int prty = getpriority(PRIO_PROCESS, 0);

    printf("pid: %d\n", pid);
    printf("tid: %d\n", tid);
    printf("current nice = %d\n", prty);

    cpu_set_t set;
    CPU_ZERO(&set);
    if (sched_getaffinity(0, sizeof(cpu_set_t), &set) == 0) {
        int is = 0;
        for (int i = 0; i < CPU_SETSIZE; i++) {
            is = CPU_ISSET(i, &set);
            printf("cpu = %i is %s\n", i, is ? "set" : "unset");
        }
    } else {
        printf("sched_getaaffinity = ERROR");
    }
}
