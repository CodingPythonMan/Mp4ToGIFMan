#pragma once

#define SCREEN_WIDTH	81		// �ܼ� ���� 80ĭ + NULL
#define SCREEN_HEIGHT	24		// �ܼ� ���� 25ĭ + NULL

class ScreenBuffer
{
public:
	void Flip();
	void Clear();
	void SpriteDraw(int X, int Y, char Sprite);
	void StringSet(int X, int Y, const char* str);

	void ConsoleInit();

private:
	// ���� �Լ�
	void ClearScreen();
	void MoveCursor(int iPosX, int iPosY);

private:
	char _ScreenBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	HANDLE  _Console;
};