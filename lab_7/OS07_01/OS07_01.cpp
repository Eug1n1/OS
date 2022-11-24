#include <iostream>
#include <ctime>
#include <Windows.h>

#define SLEEP_DELAY 100

void WINAPI loop(char* displayed_name);
HANDLE createThread(LPTHREAD_START_ROUTINE func, char* thread_name);
void EnterCriticalSectionAssem();
void LeaveCriticalSectionAssem();

int check = 0;

int main()
{
	const int size = 2;
	HANDLE threads[size];

	threads[0] = createThread((LPTHREAD_START_ROUTINE)loop, (char*)"A");
	threads[1] = createThread((LPTHREAD_START_ROUTINE)loop, (char*)"B");

	WaitForMultipleObjects(size, threads, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
	{
		CloseHandle(threads[i]);
	}

	system("pause");
	return 0;
}

HANDLE createThread(LPTHREAD_START_ROUTINE func, char* thread_name)
{
	DWORD thread_id = NULL;
	HANDLE thread = CreateThread(NULL, 0, func, thread_name, 0, &thread_id);

	if (thread == NULL) {
		throw "Error creating child thread";
	}

	return thread;
}

void WINAPI loop(char* displayed_name) {
	int pid = GetCurrentProcessId();
	int tid = GetCurrentThreadId();

	for (int i = 0; i < 90; i++)
	{
		if (i == 30) {
			EnterCriticalSectionAssem();
		}

		printf("%s:\ti: %d\tpid: %d\ttid: %u\tcheck: %d\n", displayed_name, i, pid, tid, check);

		if (i == 60) {
			LeaveCriticalSectionAssem();
		}

		Sleep(SLEEP_DELAY);
	}

	printf("%s DONE.\n", displayed_name);
}

void EnterCriticalSectionAssem()
{
	//Префикс lock, помещенный перед командой, устанавливает сигнал на линии LOCK системной шины и запрещает доступ к шине другим процессорам на время выполнения данной команды.
	//Команда BTS сохраняет значение бита, из первого операнда со смещением, указанным вторым операндом, во флаге CF, а затем устанавливает этот бит в 1.

	// нулевой бит переменной check ставиться в значение 1
	_asm
	{
	CriticalSection:
		lock bts check, 0;
		jc CriticalSection
	}
}

void LeaveCriticalSectionAssem()
{
	//Команда BTR сохраняет значение бита, из первого операнда со смещением, указанным вторым операндом, во флаге CF, а затем обнуляет этот бит.

	// нулевой бит переменной check ставиться в значение 0
	_asm lock btr check, 0
}