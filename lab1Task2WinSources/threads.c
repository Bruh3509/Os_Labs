#include <Windows.h>
#include <stdio.h>
#include <processthreadsapi.h>

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType);
void printRandNum();
void readFromConsole();

int main(int argc, char** argv) {
	SetConsoleCtrlHandler(HandlerRoutine, TRUE);
	CreateThread(NULL, 0, printRandNum, NULL, 0, NULL);
	CreateThread(NULL, 0, readFromConsole, NULL, 0, NULL);
	while (1);
	return 0;
}

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType) {
	switch (dwCtrlType)
	{
	case CTRL_C_EVENT:
		printf("CTRL_C_EVENT 0");
		break;
	case CTRL_BREAK_EVENT:
		printf("CTRL_BREAK_EVENT 1");
		break;
	case CTRL_CLOSE_EVENT:
		printf("CTRL_CLOSE_EVENT 2");
		break;
	default:
		printf("Another signal ?");
		break;
	}
	return FALSE;
}

void printRandNum() {
	while (1) {
		printf("%f\n", (float)rand() / ((float)RAND_MAX / 1));
		Sleep(3000);
	}
}

void readFromConsole() {
	while (1) {
		char str[100];
		scanf_s("%s", str, 100);
		printf("%s\n", _strrev(str));
	}
}