#include <iostream>
#include <Windows.h>
#define SECOND 10000000

PROCESS_INFORMATION createProcess(LPCWSTR path);

int main()
{
	int pid = GetCurrentProcessId();
	const int size = 2;

	HANDLE waitableTimer = CreateWaitableTimer(NULL, FALSE, L"os08_04");
	if (waitableTimer == NULL)
	{
		printf("CreateWaitableTimer failed (%d)\n", GetLastError());
		return 1;
	}

	LARGE_INTEGER liDueTime;

	liDueTime.QuadPart = -60 * SECOND;

	SetWaitableTimer(waitableTimer, &liDueTime, 60000, NULL, NULL, FALSE);

	HANDLE processes[size];
	processes[0] = createProcess(L"C:\\Users\\eug1n1\\Univer\\os\\lab_8\\Debug\\OS08_04_X.exe").hProcess;
	processes[1] = createProcess(L"C:\\Users\\eug1n1\\Univer\\os\\lab_8\\Debug\\OS08_04_X.exe").hProcess;

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
