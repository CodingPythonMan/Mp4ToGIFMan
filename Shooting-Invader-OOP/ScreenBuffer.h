#pragma once

#define SCREEN_WIDTH	81		// 콘솔 가로 80칸 + NULL
#define SCREEN_HEIGHT	24		// 콘솔 세로 25칸 + NULL

class ScreenBuffer
{
public:
	void Flip();
	void Clear();
	void SpriteDraw(int X, int Y, char Sprite);
	void StringSet(int X, int Y, const char* str);

	void ConsoleInit();

private:
	// 내부 함수
	void ClearScreen();
	void MoveCursor(int iPosX, int iPosY);

private:
	char _ScreenBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	HANDLE  _Console;
};