#include <stdio.h>
#include <windows.h>
#include "ScreenBuffer.h"

void ScreenBuffer::Flip()
{
	for (int count = 0; count < SCREEN_HEIGHT; count++)
	{
		MoveCursor(0, count);
		printf(_ScreenBuffer[count]);
	}
}

void ScreenBuffer::Clear()
{
	for (int count = 0; count < SCREEN_HEIGHT; count++)
	{
		memset(_ScreenBuffer[count], ' ', SCREEN_WIDTH);
		_ScreenBuffer[count][SCREEN_WIDTH - 1] = (char)NULL;
	}
}

void ScreenBuffer::SpriteDraw(int X, int Y, char Sprite)
{
	if (X < 0 || Y < 0 || X >= SCREEN_WIDTH - 1 || Y >= SCREEN_HEIGHT)
		return;

	_ScreenBuffer[Y][X] = Sprite;
}

void ScreenBuffer::StringSet(int X, int Y, const char* str)
{
	if (X + strlen(str) >= SCREEN_WIDTH - 1)
		return;

	memcpy(&_ScreenBuffer[Y][X], str, strlen(str));
}

//-------------------------------------------------------------
// 콘솔 제어를 위한 준비 작업.
//
//-------------------------------------------------------------
void ScreenBuffer::ConsoleInit(void)
{
	CONSOLE_CURSOR_INFO stConsoleCursor;

	//-------------------------------------------------------------
	// 화면의 커서를 안보이게끔 설정한다.
	//-------------------------------------------------------------
	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;			// 커서 크기.
	// 이상하게도 0 이면 나온다. 1로하면 안나온다.

//-------------------------------------------------------------
// 콘솔화면 (스텐다드 아웃풋) 핸들을 구한다.
//-------------------------------------------------------------
	_Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(_Console, &stConsoleCursor);
}

//-------------------------------------------------------------
// 콘솔 화면의 커서를 X, Y 좌표로 이동시킨다.
//
//-------------------------------------------------------------
void ScreenBuffer::MoveCursor(int iPosX, int iPosY)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	//-------------------------------------------------------------
	// 원하는 위치로 커서를 이동시킨다.
	//-------------------------------------------------------------
	SetConsoleCursorPosition(_Console, stCoord);
}

//-------------------------------------------------------------
// 콘솔 화면을 조기화 한다.
//
//-------------------------------------------------------------
void ScreenBuffer::ClearScreen(void)
{
	int iCountX, iCountY;

	//-------------------------------------------------------------
	// 화면 크기만큼 세로, 가로 이중 for 문을 사용하여
	// 각각의 좌표마다 printf(" ");  공백을 전부 출력 해준다.
	//-------------------------------------------------------------
	for (iCountY = 0; iCountY < SCREEN_HEIGHT; iCountY++)
	{
		for (iCountX = 0; iCountX < SCREEN_WIDTH; iCountX++)
		{
			MoveCursor(iCountX, iCountY);
			printf(" ");
		}
	}
}