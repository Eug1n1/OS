#include <iostream>
#include <Windows.h>

PROCESS_INFORMATION createProcess(LPCWSTR path);

int main()
{
	int pid = GetCurrentProcessId();
	const int size = 2;

	HANDLE processes[size];

	processes[0] = createProcess(L"C:\\Users\\eug1n1\\Univer\\os\\lab_3\\Debug\\OS03_02_1.exe").hProcess;
	processes[1] = createProcess(L"C:\\Users\\eug1n1\\Univer\\os\\lab_3\\Debug\\OS03_02_2.exe").hProcess;

	for (int i = 0; i < 10; i++)
	{
		printf("%d - %d\n", pid, i);
		Sleep(1000);
	}

	WaitForMultipleObjects(size, processes, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
	{
		CloseHandle(processes[i]);
	}

	return EXIT_SUCCESS;
}

PROCESS_INFORMATION createProcess(LPCWSTR path)
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;

	ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
	startupInfo.cb = sizeof(STARTUPINFO);

	if (CreateProcessW(path, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &processInfo))
	{
		std::cout << "Process created" << std::endl;
	}
	else
	{
		std::cout << "Error" << std::endl;
	}

	return processInfo;
}
