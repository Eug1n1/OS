#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *os04_07_t1(void *arg);

int main(int argc, char *argv[]) {
  int pid = getpid();

  pthread_t a_thread;
  void *thread_result;

  int res = pthread_create(&a_thread, NULL, os04_07_t1, NULL);

  for (int i = 0; i < 100; i++) {
    printf("MAIN:\ti: %d, pid: %d\n", i, pid);
    sleep(1);

    if (i == 30) {
      printf("MAIN sleeping\n");
      sleep(15);
      printf("MAIN awakened\n");
    }
  }

  int status = pthread_join(a_thread, (void **)&thread_result);

  return 0;
}

void *os04_07_t1(void *arg) {
  int pid = getpid();

  for (int i = 0; i < 75; i++) {
    printf("T1:\ti: %d, pid: %d\n", i, pid);
    sleep(1);

    if (i == 50) {
      printf("T1 sleeping\n");
      sleep(10);
      printf("T1 awakened\n");
    }
  }

  pthread_exit("t1 done");
}
