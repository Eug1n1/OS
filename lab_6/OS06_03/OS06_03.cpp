#include <iostream>
#include <Windows.h>

#define MB 1024*1024

int main()
{
	setlocale(LC_ALL, "windows1251");

	int page_count = 256;
	int page_size;
	int memory_size;
	int* virtArray;
	SYSTEM_INFO system_info;
	
	GetSystemInfo(&system_info);

	page_size = system_info.dwPageSize;
	memory_size = page_count * page_size;

	virtArray = (int*)VirtualAlloc(NULL, memory_size, MEM_COMMIT, PAGE_READWRITE);

	for (int i = 0; i < memory_size / sizeof(int); i++)
	{
		virtArray[i] = i;
	}

	int char1 = 0xd8;
	int char2 = 0xf3;
	int char3 = 0xec;

	int index = (char1 * page_size + ((char2 << 4) | (char3 >> 4))) / sizeof(int);
	std::cout << virtArray[index] << std::endl;

	if (VirtualFree(virtArray, NULL, MEM_RELEASE)) {
		std::cout << "Error free" << std::endl;
	}
}

// Ш 216 D8 216 * 4096 = 884736 first byte of 216's page
// у 243 F3 11110011 => 111100111110 3902 F3E offset
// м 236 EC 11101100 => ^

// (884736 + 3902) / 4 (sizeof(int) = 4) = 222159 