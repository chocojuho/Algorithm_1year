#include "tool.h"


int COLS = 50;
int LOWS = 20;
void setWindowSize(int cols, int lows)
{
	COLS = cols;
	LOWS = lows;

	char buffer[128];
	sprintf(buffer, "mode con:cols=%d lines=%d", cols, lows);
	system(buffer);
}
void gotoxy(int x, int y) {
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };

	// 콘솔화면의 커서 위치를 pos로 변경
	SetConsoleCursorPosition(hOutput, pos);
}

void clear()
{
	unsigned long dw;
	COORD pos = { 0,0 };
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),' ',COLS*LOWS,pos,&dw);
	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), getColorBit(0,1,1,1,1), COLS * LOWS, pos, &dw);
	textColor(getColorBit(0,1,1,1,1));
	gotoxy(0, 0);
}

void textColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int getColorBit(int background, int bright, int red, int green, int blue)
{
	return (bright << 3 | red << 2 | green << 1 | blue)<<background*4;
}

