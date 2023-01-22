#include "tool.h"

using namespace std;

int userInput = 0;
int frameCount;
int sizer = 3;

int processInput() {
	if (kbhit()) {
		char c = getch();
		if (c == 'd') {
			userInput++;
		}
		if (c == 'a') {
			userInput--;
		}
		if (c == ' ') {
			return 1;
		}
	}
	return 0;
}

void update(int input) {
	frameCount++;
	if (frameCount > sizer || userInput != 0) {
		sizer += userInput;
		userInput = 0;
		frameCount = 0;
		sizer = (sizer > 20) ? 20 : (sizer < 3) ? 3 : sizer;
		clear();
		return;
	}
	int x = sizer - frameCount;
	int y = frameCount - 1;
	gotoxy(x, y);
	for (int i = 0; i < 2 * frameCount - 1; i++) {
		cout << "*";
	}
}

int main()
{
	int timer = 0;
	int frameRate = 1000/10;
	int input;
	while (1) {
		timer = clock();
		input = processInput();
		if (input == 1) {
			break;
		}
		update(input);
		int tmp = timer + frameRate - clock();
		if (tmp > 0) {
			Sleep(tmp);
		}
	}
	return 0;
}