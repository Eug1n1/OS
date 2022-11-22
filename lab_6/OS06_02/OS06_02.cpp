#include <iostream>
#include <Windows.h>

int main()
{
	int pid = GetCurrentProcessId();

	for (int i = 0; i < 1000; i++)
	{
		printf("i: %d\tpid: %d\n", i, pid);
		Sleep(1000);
	}
}