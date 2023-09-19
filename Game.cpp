#include <Windows.h>
#include "Console.h"
#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Render.h"
#include "DataRead.h"
#include "Monster.h"
#include "Missile.h"

int gStageCount;
int gPresentStage = 1;

void Game_Initialize()
{
	timeBeginPeriod(1);
	cs_Initial();
	DataRead_MovePattern();
	DataRead_Monster();
	gStageCount = DataRead_Stage();
	Monster_Set(gPresentStage);
	Player_Initial();
}

bool Game_KeyProcess()
{
	switch (gSceneType)
	{
	case SceneType::TITLE:
		if (GetAsyncKeyState(VK_RETURN))
		{
			gSceneType = SceneType::STAGE;
			break;
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
		{
			return false;
		}
		break;

	case SceneType::STAGE:
		// 왼쪽 방향키.
		if (GetAsyncKeyState(VK_LEFT))
		{
			Player_xMove(-1);
		}
		// 오른쪽 방향키.
		if (GetAsyncKeyState(VK_RIGHT))
		{
			Player_xMove(1);
		}
		// 위쪽 방향키.
		if (GetAsyncKeyState(VK_UP) & 0x8001)
		{
			Player_yMove(-1);
		}
		// 아래쪽 방향키.
		if (GetAsyncKeyState(VK_DOWN) & 0x8001)
		{
			Player_yMove(1);
		}

		// 콘트롤 키. (미사일 키)
		if (GetAsyncKeyState(VK_CONTROL))
		{
			Player_MissileAttack();
		}

		// ESC 키. (일시정지)
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
		{
			gSceneType = SceneType::STOP;
		}
		break;
	case SceneType::STOP:
		if (GetAsyncKeyState(VK_RETURN))
		{
			gSceneType = SceneType::STAGE;
			break;
		}

		if (GetAsyncKeyState(0x51) & 0x8001)
		{
			return false;
		}
		break;
	case SceneType::GAMEOVER:
	case SceneType::CLEAR:
		if (GetAsyncKeyState(VK_RETURN))
		{
			gSceneType = SceneType::TITLE;
			break;
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
		{
			return false;
		}
		break;
	}

	return true;
}

void Game_Update()
{
	switch (gSceneType)
	{
	case SceneType::STAGE:
		Missile_Update();
		Monster_Update();
		Player_Update();
		break;
	default:
		break;
	}
}

void Game_Render()
{
	Buffer_Clear();

	switch(gSceneType)
	{
	case SceneType::TITLE:
		Scene_DrawTitle();
		break;
	case SceneType::STAGE:
		Missile_Draw();
		Monster_Draw();
		Player_Draw();
		break;
	case SceneType::STOP:
		Scene_DrawStop();
		break;
	case SceneType::GAMEOVER:
		Scene_DrawGameOver();
		break;
	case SceneType::CLEAR:
		Scene_DrawClear();
		break;
	}

	Buffer_Flip();
}