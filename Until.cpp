#include "Until.h"

void GoToXY(int x, int y)
{
	HANDLE Output;
	COORD Cursor_Pos = { x, y };
	Output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Output, Cursor_Pos);
}

int GetRandomNumber(int maxNum)
{
	return (((rand() * 214013 + 2531011) >> 16) & 0x7fff) % maxNum;
}