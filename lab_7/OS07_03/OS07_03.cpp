#include <iostream>
#include <Windows.h>

PROCESS_INFORMATION createProcess(LPCWSTR path);

int main()
{
	int pid = GetCurrentProcessId();
	const int size = 2;
	HANDLE mutex;
	HANDLE processes[size];

	processes[0] = createProcess(L"C:\\Users\\eug1n1\\Univer\\os\\lab_7\\Debug\\OS07_03A.exe").hProcess;
	processes[1] = createProcess(L"C:\\Users\\eug1n1\\Univer\\os\\lab_7\\Debug\\OS07_03B.exe").hProcess;

	mutex = CreateMutex(NULL, FALSE, L"os07_03");

	for (int i = 0; i < 90; i++)
	{
		if (i == 30) {
			WaitForSingleObject(mutex, INFINITE);
		}
		else if (i == 60) {
			ReleaseMutex(mutex);
		}

		printf("OS07_03:\ti: %d\tpid: %d\n", i, pid);
		Sleep(100);
	}

	WaitForMultipleObjects(size, processes, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
	{
		CloseHandle(processes[i]);
	}

	CloseHandle(mutex);

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
