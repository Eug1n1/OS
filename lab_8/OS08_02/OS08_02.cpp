#include <iostream>
#include <chrono>

int main()
{
	auto start = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds;

	bool isDisplayed = false;
	int8_t previous_second = 0;

	unsigned long i;

	for (i = 0; (elapsed_seconds = std::chrono::system_clock::now() - start).count() < 15; i++) {

		if (int(elapsed_seconds.count()) != previous_second) {
			isDisplayed = false;
		}

		if (!isDisplayed && (
			int(elapsed_seconds.count()) == 5 || int(elapsed_seconds.count()) == 10
			)) {
			isDisplayed = true;

			printf("i: %d, s: %f\n", i, elapsed_seconds.count());
		}

		previous_second = int(elapsed_seconds.count());
	}

	printf("final: %d", i);

	return EXIT_SUCCESS;
}
