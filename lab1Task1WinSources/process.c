#include <stdio.h>
#include <Windows.h>

int main(int argc, char** argv)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcess(
		L"D:\\Programming\\OsLab\\lab1\\x64\\Debug\\Signal.exe",
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi)) 
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
	}

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}