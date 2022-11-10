#include <iostream>
#include <Windows.h>

int main()
{
    int pid = GetCurrentProcessId();
    int tid = GetCurrentThreadId();

	for (size_t i = 0; i < 100; i++)
	{
		printf("pid: %d, tid: %d\n", pid, tid);
		Sleep(1000);
	}
}
