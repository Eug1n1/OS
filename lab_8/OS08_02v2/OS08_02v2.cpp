#include <iostream>

int main()
{
	clock_t current_time, start_time = clock();

	bool isDisplayed = false;
	int8_t previous_second = 0;

	unsigned long i;

	for (i = 0; (current_time = ((clock() - start_time) / CLOCKS_PER_SEC)) < 15; i++) {

		if (current_time != previous_second) {
			isDisplayed = false;
		}

		if (!isDisplayed && (
			current_time == 5 || current_time == 10
			)) {
			isDisplayed = true;

			printf("i: %d, s: %d\n", i, current_time);
		}

		previous_second = current_time;
	}

	printf("final: %d", i);

	return EXIT_SUCCESS;
}
