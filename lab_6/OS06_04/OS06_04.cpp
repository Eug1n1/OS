#include <iostream>
#include <Windows.h>

void sh(HANDLE pheap);

int main()
{
	HANDLE heap = GetProcessHeap();
	int* array;

	sh(heap);
	system("pause");

	array = (int*)malloc(300000 * sizeof(int));
	for (int i = 0; i < 300000; i++)
	{
		array[i] = i;
	}

	sh(heap);
}

void sh(HANDLE pheap) {
	PROCESS_HEAP_ENTRY heap_info;
	heap_info.lpData = NULL;
	long size = 0;

	while (HeapWalk(pheap, &heap_info))
	{
		std::cout << "--  address = " << std::hex << heap_info.lpData
			<< ", size = " << std::dec << heap_info.cbData
			<< ((heap_info.wFlags & PROCESS_HEAP_REGION) ? " R" : "")
			<< ((heap_info.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE) ? " U" : "")
			<< ((heap_info.wFlags & PROCESS_HEAP_ENTRY_BUSY) ? " B" : "")
			<< "\n";
	}

	printf("size: %d\n", size);
}
