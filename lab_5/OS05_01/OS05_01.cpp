#include <iostream>
#include <Windows.h>
#include <bitset>

int main()
{
	int pid = GetCurrentProcessId();
	int tid = GetCurrentThreadId();
	int prty = GetPriorityClass(GetCurrentProcess());

	printf("pid: %d\n", pid);
	printf("tid: %d\n", tid);
	printf("proc_prty: %d ", prty);
	switch (prty) {
		case IDLE_PRIORITY_CLASS:
			printf("idle\n");
			break;
		case BELOW_NORMAL_PRIORITY_CLASS:
			printf("below normal\n");
			break;
		case NORMAL_PRIORITY_CLASS:
			printf("normal\n");
			break;
		case ABOVE_NORMAL_PRIORITY_CLASS:
			printf("above normal\n");
			break;
		case HIGH_PRIORITY_CLASS:
			printf("high\n");
			break;
		case REALTIME_PRIORITY_CLASS:
			printf("realtime\n");
			break;
	}

	int thr_prty = GetThreadPriority(GetCurrentThread());
	printf("thr_prty: %d ", thr_prty);
	switch (thr_prty) {
		case THREAD_PRIORITY_LOWEST:
			printf("lowest\n");
			break;
		case THREAD_PRIORITY_BELOW_NORMAL:
			printf("below normal\n");
			break;
		case THREAD_PRIORITY_NORMAL:
			printf("normal\n");
			break;
		case THREAD_PRIORITY_ABOVE_NORMAL:
			printf("above normal\n");
			break;
		case THREAD_PRIORITY_HIGHEST:
			printf("highest\n");
			break;
		case THREAD_PRIORITY_IDLE:
			printf("idle\n");
			break;
		case THREAD_PRIORITY_TIME_CRITICAL:
			printf("time critical\n");
			break;
	}

	DWORD_PTR proc_affinity = NULL, sys_affinity = NULL;
	if (!GetProcessAffinityMask(GetCurrentProcess(), &proc_affinity, &sys_affinity)) {
		throw "GetProcessAffinityMask";
	}

	std::bitset<8> proc_affinity_bits(proc_affinity);
	std::cout << "proc_affinity: " << proc_affinity_bits << " (" << proc_affinity << ")\n";

	printf("processors: %d\n", proc_affinity_bits.count());

	int pref_processor = SetThreadIdealProcessor(GetCurrentThread(), MAXIMUM_PROCESSORS);
	printf("pref_processor: %d\n", pref_processor);

}
