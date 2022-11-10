#include <iostream>
#include <Windows.h>

void printProcInfo();

int main()
{
	for (int i = 0; i < 1000000; i++)
	{
		if (i % 1000 == 0) {
			printf("i: %d\t", i);
			printProcInfo();
			Sleep(200);
		}
	}
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
