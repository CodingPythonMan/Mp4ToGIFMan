#include <stdio.h>
#include <Windows.h>
#include "Game.h"

#pragma comment(lib, "winmm.lib")

int main(void)
{
	Game_Initialize();
	
	//--------------------------------------------------------------------
	// ������ ���� ����
	// �� ������  1�� ���� 1������ �̴�.
	//--------------------------------------------------------------------
	unsigned long delay = 0;
	unsigned long beforeTime = timeGetTime();
	int FrameCount = 0;
	DWORD Tick = timeGetTime();
	while (1)
	{
		// Ű���� �Է�
		if (false == Game_KeyProcess())
			return 0;

		// ������
		Game_Update();

		// ������
		Game_Render();

		FrameCount++;
		if (timeGetTime() - Tick >= 1000)
		{
			printf("%d \n", FrameCount);
			FrameCount = 0;
			Tick = timeGetTime();
		}

		// ������ ����
		if (delay < 20)
		{
			Sleep(20 - delay);
			beforeTime += 20;
			delay = timeGetTime() - beforeTime;
		}
	}

	return 0;
}