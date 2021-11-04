#include <iostream>
#include <Windows.h>

int main()
{
	int pid = GetCurrentProcessId();

	for (int i = 0; i < 1000; i++)
	{
		printf("%d - %d\n", pid, i);
		Sleep(2000);
	}
}
