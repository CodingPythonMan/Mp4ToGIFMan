#include <Windows.h>
#include <stdio.h>
#include "Console.h"
#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Render.h"
#include "DataRead.h"
#include "Monster.h"

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
			gPlayer._X--;
		}
		// 오른쪽 방향키.
		if (GetAsyncKeyState(VK_RIGHT))
		{
			gPlayer._X++;
		}
		// 위쪽 방향키.
		if (GetAsyncKeyState(VK_UP) & 0x8001)
		{
			gPlayer._Y--;
		}
		// 아래쪽 방향키.
		if (GetAsyncKeyState(VK_DOWN) & 0x8001)
		{
			gPlayer._Y++;
		}

		//-------------------------------------------------------------
		// 플레이어 이동 반경 제한.
		// 게임 화면에서 플레이어가 이동 가능한 구역을 제한한다.
		//-------------------------------------------------------------

		gPlayer._X = max(gPlayer._X, 0);
		gPlayer._X = min(gPlayer._X, 79);
		gPlayer._Y = max(gPlayer._Y, 0);
		gPlayer._Y = min(gPlayer._Y, 23);

		// 콘트롤 키. (미사일 키)
		if (GetAsyncKeyState(VK_CONTROL))
		{
			/*
			_Missiles[_MissileCount].X = _Player.X;
			_Missiles[_MissileCount].Y = _Player.Y - 1;
			_Missiles[_MissileCount].Visible = 1;

			_MissileCount++;*/
		}

		// ESC 키. (일시정지)
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
	case SceneType::TITLE:

		break;

	case SceneType::STAGE:
		Monster_Update();
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
		Monster_Draw();
		break;
	}

	Buffer_Flip();
}