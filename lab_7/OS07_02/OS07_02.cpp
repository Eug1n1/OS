#include <iostream>
#include <windows.h>

#define SLEEP_DELAY 1000

void WINAPI loop(char* name);
HANDLE createThread(LPTHREAD_START_ROUTINE func, char* thread_name);

CRITICAL_SECTION critical_section;

int main()
{
	int pid = GetCurrentProcessId();
	const int size = 2;

	HANDLE threads[size];

	threads[0] = createThread((LPTHREAD_START_ROUTINE)loop, (char*)"A");
	threads[1] = createThread((LPTHREAD_START_ROUTINE)loop, (char*)"B");

	InitializeCriticalSection(&critical_section);

	for (int i = 0; i < 100; i++)
	{

		if (i == 30) {
			EnterCriticalSection(&critical_section);
		}

		printf("MAIN:\ti: %d, pid: %d\n", i, pid);

		if (i == 60) {
			LeaveCriticalSection(&critical_section);
		}

		Sleep(SLEEP_DELAY);
	}

	WaitForMultipleObjects(size, threads, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
	{
		CloseHandle(threads[i]);
	}

	DeleteCriticalSection(&critical_section);

	return EXIT_SUCCESS;
}

HANDLE createThread(LPTHREAD_START_ROUTINE func, char* thread_name)
{
	DWORD thread_id = NULL;
	HANDLE thread = CreateThread(NULL, 0, func, thread_name, 0, &thread_id);

	if (thread == NULL) {
		throw "Error creating child thread";
	}

	return thread;
}

void WINAPI loop(char* displayed_name) {
	int pid = GetCurrentProcessId();
	int tid = GetCurrentThreadId();

	for (int i = 0; i < 90; i++)
	{
		if (i == 30) {
			EnterCriticalSection(&critical_section);
		}

		printf("%s:\ti: %d, pid: %d, tid: %u\n", displayed_name, i, pid, tid);

		if (i == 60) {
			LeaveCriticalSection(&critical_section);
		}

		Sleep(SLEEP_DELAY);
	}

	printf("%s DONE.\n", displayed_name);
}