#include <iostream>
#include <Windows.h>

void sh(HANDLE pheap);

int main()
{
	int* array;
	HANDLE heap = HeapCreate(HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 4096 * 1024, 0);

	sh(heap);

	array = (int*)HeapAlloc(heap, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 300000 * sizeof(int));

	sh(heap);

	HeapFree(heap, HEAP_NO_SERIALIZE, array);
	HeapDestroy(heap);
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
