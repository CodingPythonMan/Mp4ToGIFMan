#include <stdio.h>
#include <memory.h>
#include <cstring>
#include "Render.h"

char gScreenBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];

void Buffer_Flip(void)
{
	for (int count = 0; count < SCREEN_HEIGHT; count++)
	{
		cs_MoveCursor(0, count);
		printf(gScreenBuffer[count]);
	}
}

void Buffer_Clear(void)
{
	for (int count = 0; count < SCREEN_HEIGHT; count++)
	{
		memset(gScreenBuffer[count], ' ', SCREEN_WIDTH);
		gScreenBuffer[count][SCREEN_WIDTH - 1] = (char)NULL;
	}
}

void Sprite_Draw(int X, int Y, char Sprite)
{
	if (X < 0 || Y < 0 || X >= SCREEN_WIDTH - 1 || Y >= SCREEN_HEIGHT)
		return;

	gScreenBuffer[Y][X] = Sprite;
}

void String_Set(int X, int Y, const char* str)
{
	if (X + strlen(str) >= SCREEN_WIDTH - 1)
		return;

	memcpy(&gScreenBuffer[Y][X], str, strlen(str));
}