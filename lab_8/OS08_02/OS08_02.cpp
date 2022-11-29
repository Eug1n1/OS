#include <iostream>
#include <chrono>

int main()
{
	auto start = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds;

	unsigned long i;


	for (i = 0; (elapsed_seconds = std::chrono::system_clock::now() - start).count() < 15; i++) {

		if (elapsed_seconds.count() == 5 || elapsed_seconds.count() == 10) {
			printf("i: %d, s: %d\n", i, int(elapsed_seconds.count()));
		}
	}

	printf("final: %d", i);

	return EXIT_SUCCESS;
}
