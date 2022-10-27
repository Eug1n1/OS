#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <TlHelp32.h>


int main()
{
    DWORD pid = GetCurrentProcessId();
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);

    PROCESSENTRY32 peProcessEntry;
    peProcessEntry.dwSize = sizeof(PROCESSENTRY32);

    printf("Current PID = %d\n-------------------------------------\n", pid);

    try
    {
        if (!Process32First(snap, &peProcessEntry))
        {
            throw "Process32First";
        }

        do
        {
            printf("Name: %ls\n", peProcessEntry.szExeFile);
            printf("PID: %d, Parent PID: %d\n", peProcessEntry.th32ProcessID, peProcessEntry.th32ParentProcessID);

            if (peProcessEntry.th32ProcessID == pid)
            {
                std::cout << "--> current process\n";
            }

            printf("---------------------------------------------\n");
        } while (Process32Next(snap, &peProcessEntry));
    }
    catch (char* msg)
    {
        std::cout << "ERROR: " << msg << std::endl;
    }

    system("pause");
    return 0;
}
