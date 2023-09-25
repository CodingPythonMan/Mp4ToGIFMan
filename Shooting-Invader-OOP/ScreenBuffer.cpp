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
// �ܼ� ��� ���� �غ� �۾�.
//
//-------------------------------------------------------------
void ScreenBuffer::ConsoleInit(void)
{
	CONSOLE_CURSOR_INFO stConsoleCursor;

	//-------------------------------------------------------------
	// ȭ���� Ŀ���� �Ⱥ��̰Բ� �����Ѵ�.
	//-------------------------------------------------------------
	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;			// Ŀ�� ũ��.
	// �̻��ϰԵ� 0 �̸� ���´�. 1���ϸ� �ȳ��´�.

//-------------------------------------------------------------
// �ܼ�ȭ�� (���ٴٵ� �ƿ�ǲ) �ڵ��� ���Ѵ�.
//-------------------------------------------------------------
	_Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(_Console, &stConsoleCursor);
}

//-------------------------------------------------------------
// �ܼ� ȭ���� Ŀ���� X, Y ��ǥ�� �̵���Ų��.
//
//-------------------------------------------------------------
void ScreenBuffer::MoveCursor(int iPosX, int iPosY)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	//-------------------------------------------------------------
	// ���ϴ� ��ġ�� Ŀ���� �̵���Ų��.
	//-------------------------------------------------------------
	SetConsoleCursorPosition(_Console, stCoord);
}

//-------------------------------------------------------------
// �ܼ� ȭ���� ����ȭ �Ѵ�.
//
//-------------------------------------------------------------
void ScreenBuffer::ClearScreen(void)
{
	int iCountX, iCountY;

	//-------------------------------------------------------------
	// ȭ�� ũ�⸸ŭ ����, ���� ���� for ���� ����Ͽ�
	// ������ ��ǥ���� printf(" ");  ������ ���� ��� ���ش�.
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