#include <iostream>
#include <Windows.h>

int main()
{
	HANDLE hTimer = NULL;
	LARGE_INTEGER liDueTime;

	clock_t current_time, start_time = clock();

	bool isDisplayed = false;
	int8_t previous_second = 0;

	unsigned long i;

	liDueTime.QuadPart = -10000000LL;
	
	hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
	if (NULL == hTimer)
	{
		printf("CreateWaitableTimer failed (%d)\n", GetLastError());
		return 1;
	}

	for (i = 0; (current_time = ((clock() - start_time) / CLOCKS_PER_SEC)) < 15; i++) {

		if (current_time != previous_second) {
			isDisplayed = false;
		}

		if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0))
		{
			printf("SetWaitableTimer failed (%d)\n", GetLastError());
			return 2;
		}

		if (!isDisplayed && current_time % 3 == 0) {
			isDisplayed = true;

			printf("i: %d, s: %d\n", i, current_time);
		}

		previous_second = current_time;

		WaitForSingleObject(hTimer, INFINITE);
	}

	printf("final: %d", i);

	return EXIT_SUCCESS;
}
