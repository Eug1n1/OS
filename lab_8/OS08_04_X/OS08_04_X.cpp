#include <iostream>
#include <windows.h>

void os08_04_wait();
HANDLE createThread(LPTHREAD_START_ROUTINE func);
bool isSimple(int number);

bool isTimeout = false;

int main()
{
	int pid = GetCurrentProcessId();
	const int size = 1;

	HANDLE threads[size];

	threads[0] = createThread((LPTHREAD_START_ROUTINE)os08_04_wait);

	for (unsigned long i = 0, index = 0; !isTimeout; i++) {
		if (isSimple(i)) {
			printf("index: %d\ti: %d\n", index++, i);
		}
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

void os08_04_wait() {
	HANDLE waitableTimer = OpenWaitableTimer(TIMER_ALL_ACCESS, FALSE, L"os08_04");
	if (waitableTimer == NULL)
	{
		throw "CreateWaitableTimer failed";
	}

	WaitForSingleObject(waitableTimer, INFINITE);

	isTimeout = true;

	CloseHandle(waitableTimer);
}

bool isSimple(int number) {
	for (int i = 2; i <= number / 2; i++) {
		if ((number % i) == 0) {
			return 0;
		}
	}

	return 1;
}
