using namespace std;
#include <iostream>
#include <Windows.h>

PROCESS_INFORMATION createProcess(LPCWSTR path, int prty, DWORD_PTR mask);

int main(int argc, char *argv[])
{
	int mask = atoi(argv[1]);
	int prty1 = atoi(argv[2]);
	int prty2 = atoi(argv[3]);

	printf("mask: %d\n", mask);
	printf("prty_1: %d\n", prty1);
	printf("prty_2: %d\n", prty2);

	const int size = 2;
	HANDLE processes[size];
	processes[0] = createProcess(L"C:\\Users\\eug1n1\\Univer\\os\\lab_5\\x64\\Debug\\OS05_02x.exe", prty1, mask).hProcess;
	processes[1] = createProcess(L"C:\\Users\\eug1n1\\Univer\\os\\lab_5\\x64\\Debug\\OS05_02x.exe", prty2, mask).hProcess;

	WaitForMultipleObjects(size, processes, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
	{
		CloseHandle(processes[i]);
	}

	return EXIT_SUCCESS;
}

PROCESS_INFORMATION createProcess(LPCWSTR path, int prty, DWORD_PTR mask)
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;

	ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
	startupInfo.cb = sizeof(STARTUPINFO);

	if (CreateProcessW(path, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | prty, NULL, NULL, &startupInfo, &processInfo))
	{
		std::cout << "Process created" << std::endl;
	}
	else
	{
		std::cout << "Error" << std::endl;
	}

	//if (!SetPriorityClass(processInfo.hProcess, prty)) {
	//	throw "SetPriorityClass";
	//}

	if (!SetProcessAffinityMask(processInfo.hProcess, mask)) {
		throw "SetProcessAffinityMask";
	}

	return processInfo;
}

