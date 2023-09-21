#include <stdio.h>
#include <Windows.h>
#include "Game.h"

#pragma comment(lib, "winmm.lib")

int main(void)
{
	Game_Initialize();
	
	//--------------------------------------------------------------------
	// 게임의 메인 루프
	// 이 루프가  1번 돌면 1프레임 이다.
	//--------------------------------------------------------------------
	unsigned long delay = 0;
	unsigned long beforeTime = timeGetTime();
	int FrameCount = 0;
	DWORD Tick = timeGetTime();
	while (1)
	{
		// 키보드 입력
		if (false == Game_KeyProcess())
			return 0;

		// 로직부
		Game_Update();

		// 랜더링
		Game_Render();

		FrameCount++;
		if (timeGetTime() - Tick >= 1000)
		{
			printf("%d \n", FrameCount);
			FrameCount = 0;
			Tick = timeGetTime();
		}

		// 프레임 조절
		if (delay < 20)
		{
			Sleep(20 - delay);
			beforeTime += 20;
			delay = timeGetTime() - beforeTime;
		}
	}

	return 0;
}