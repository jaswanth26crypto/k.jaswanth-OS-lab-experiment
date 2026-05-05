#include <stdio.h>
#include <windows.h>

int main() {
    PROCESS_INFORMATION pi;
    STARTUPINFO si;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create child process (opens Notepad as example)
    if (!CreateProcess(
        NULL,
        "notepad.exe",
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi)) {

        printf("Process creation failed\n");
        return 1;
    }

    printf("\n--- Parent Process ---\n");
    printf("Parent PID: %lu\n", GetCurrentProcessId());

    printf("\n--- Child Process ---\n");
    printf("Child PID: %lu\n", pi.dwProcessId);

    printf("\nNote: Windows does not directly support getppid()\n");

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
