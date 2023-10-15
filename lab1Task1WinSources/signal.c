#include <stdio.h>
#include <Windows.h>

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType);

int main(int argc, char** argv)
{
	SetConsoleCtrlHandler(HandlerRoutine, TRUE);
	while (1);
	return 0;
}

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)
{
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