#include <iostream>
#include <Windows.h>

void os05_03();
void printProcInfo();
HANDLE createThread(LPTHREAD_START_ROUTINE func, int prty);

int main(int argc, char* argv[])
{
	int mask = atoi(argv[1]);
	int proc_prty = atoi(argv[2]);
	int prty1 = atoi(argv[3]);
	int prty2 = atoi(argv[4]);

	printf("mask: %d\n", mask);
	printf("proc_prty: %d\n", proc_prty);
	printf("prty_1: %d\n", prty1);
	printf("prty_2: %d\n\n", prty2);

	HANDLE curr_proc = GetCurrentProcess();

	if (!SetPriorityClass(curr_proc, proc_prty)) {
		throw "SetPriorityClass";
	}
	
	if (!SetProcessAffinityMask(curr_proc, mask)) {
		throw "SetProcessAffinityMask";
	}

	const int size = 2;
	HANDLE threads[size];

	threads[0] = createThread((LPTHREAD_START_ROUTINE)os05_03, prty1);
	threads[1] = createThread((LPTHREAD_START_ROUTINE)os05_03, prty2);

	WaitForMultipleObjects(size, threads, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
	{
		CloseHandle(threads[i]);
	}

	return EXIT_SUCCESS;
}

HANDLE createThread(LPTHREAD_START_ROUTINE func, int prty)
{
	DWORD ChildId = NULL;
	HANDLE hChild = CreateThread(NULL, 0, func, NULL, CREATE_SUSPENDED, &ChildId);

	if (hChild == NULL) {
		throw "Error creating child thread";
	}

	if (!SetThreadPriority(hChild, prty)) {
		throw "SetThreadPriority";
	}

	ResumeThread(hChild);

	return hChild;
}

void os05_03() {
	auto time = clock();
	for (int i = 0; i < 1000000; i++)
	{
		if (i % 1000 == 0) {
			printf("i: %d\t", i);
			printProcInfo();
			Sleep(20);
		}
	}
	std::cout << "time: " << clock() - time << "\n";
}

void printProcInfo() {
	int pid = GetCurrentProcessId();
	int tid = GetCurrentThreadId();
	int prty = GetPriorityClass(GetCurrentProcess());


	printf("pid: %d\t", pid);
	printf("tid: %d\t", tid);
	printf("proc_prty: %d ", prty);
	switch (prty) {
	case IDLE_PRIORITY_CLASS:
		printf("IDLE_PRIORITY_CLASS\t");
		break;
	case BELOW_NORMAL_PRIORITY_CLASS:
		printf("BELOW_NORMAL_PRIORITY_CLASS\t");
		break;
	case NORMAL_PRIORITY_CLASS:
		printf("NORMAL_PRIORITY_CLASS\t");
		break;
	case ABOVE_NORMAL_PRIORITY_CLASS:
		printf("ABOVE_NORMAL_PRIORITY_CLASS\t");
		break;
	case HIGH_PRIORITY_CLASS:
		printf("HIGH_PRIORITY_CLASS\t");
		break;
	case REALTIME_PRIORITY_CLASS:
		printf("REALTIME_PRIORITY_CLASS\t");
		break;
	}

	int thr_prty = GetThreadPriority(GetCurrentThread());
	printf("thr_prty: %d\t", thr_prty);

	//switch (thr_prty) {
	//	case THREAD_PRIORITY_LOWEST:
	//		printf("THREAD_PRIORITY_LOWEST\t");
	//		break;
	//	case THREAD_PRIORITY_BELOW_NORMAL:
	//		printf("THREAD_PRIORITY_BELOW_NORMAL\t");
	//		break;
	//	case THREAD_PRIORITY_NORMAL:
	//		printf("THREAD_PRIORITY_NORMAL\t");
	//		break;
	//	case THREAD_PRIORITY_ABOVE_NORMAL:
	//		printf("THREAD_PRIORITY_ABOVE_NORMAL\t");
	//		break;
	//	case THREAD_PRIORITY_HIGHEST:
	//		printf("THREAD_PRIORITY_HIGHEST\t");
	//		break;
	//	case THREAD_PRIORITY_IDLE:
	//		printf("THREAD_PRIORITY_IDLE\t");
	//		break;
	//	case THREAD_PRIORITY_TIME_CRITICAL:
	//		printf("THREAD_PRIORITY_TIME_CRITICAL\t");
	//		break;
	//}

	int curr_processor = GetCurrentProcessorNumber();
	printf("curr_processor: %d\n", curr_processor);
}
