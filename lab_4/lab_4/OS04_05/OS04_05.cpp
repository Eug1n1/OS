#include <iostream>
#include <windows.h>

void os04_02_t1();
void os04_02_t2();
HANDLE createThread(LPTHREAD_START_ROUTINE func);

int main()
{
	int pid = GetCurrentProcessId();
	const int size = 2;

	HANDLE threads[size];

	threads[0] = createThread((LPTHREAD_START_ROUTINE)os04_02_t1);
	threads[1] = createThread((LPTHREAD_START_ROUTINE)os04_02_t2);

	for (int i = 0; i < 100; i++)
	{
		printf("MAIN:\ti: %d, pid: %d\n", i, pid);

		if (i == 40) {
			TerminateThread(threads[1], 0);
			printf("T2 TERMINATED\n");
		}

		Sleep(1000);
	}

	WaitForMultipleObjects(size, threads, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
	{
		CloseHandle(threads[i]);
	}

	return EXIT_SUCCESS;
}

HANDLE createThread(LPTHREAD_START_ROUTINE func)
{
	DWORD ChildId = NULL;
	HANDLE hChild = CreateThread(NULL, 0, func, NULL, 0, &ChildId);

	if (hChild == NULL) {
		throw "Error creating child thread";
	}

	return hChild;
}

void os04_02_t1() {
	int pid = GetCurrentProcessId();
	int tid = GetCurrentThreadId();

	for (int i = 0; i < 50; i++)
	{
		printf("T1:\ti: %d, pid: %d, tid: %d\n", i, pid, tid);
		Sleep(1000);
	}

	printf("T1 DONE.\n");
}

void os04_02_t2() {
	int pid = GetCurrentProcessId();
	int tid = GetCurrentThreadId();

	for (int i = 0; i < 125; i++)
	{
		printf("T2:\ti: %d, pid: %d, tid: %d\n", i, pid, tid);
		Sleep(1000);
	}

	printf("T2 DONE.\n");
}
