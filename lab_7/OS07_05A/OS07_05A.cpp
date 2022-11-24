#include <iostream>
#include <Windows.h>

int main()
{
	int pid = GetCurrentProcessId();
	HANDLE event = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"os07_05");

	WaitForSingleObject(event, INFINITE);
	SetEvent(event);
	for (int i = 0; i < 90; i++)
	{
		printf("OS07_05B:\ti: %d\tpid:\t%d\n", i, pid);
		Sleep(100);
	}

	CloseHandle(event);
}
