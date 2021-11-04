#include <iostream>
#include <Windows.h>

int main()
{
	int pid = GetCurrentProcessId();

	for (int i = 0; i < 125; i++)
	{
		std::cout << pid << std::endl;
		Sleep(1000);
	}
}
