#include "Until.h"
#include <cstdlib>
#include <ctime>

void GoToXY(int x, int y)
{
	HANDLE Output;
	COORD Cursor_Pos = { x, y };
	Output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Output, Cursor_Pos);
}

int GetRandomNumber(int maxNum)
{
	return rand() % maxNum;
}