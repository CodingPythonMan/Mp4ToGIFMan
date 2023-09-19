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
		// ���� ����Ű.
		if (GetAsyncKeyState(VK_LEFT))
		{
			gPlayer._x--;
		}
		// ������ ����Ű.
		if (GetAsyncKeyState(VK_RIGHT))
		{
			gPlayer._x++;
		}
		// ���� ����Ű.
		if (GetAsyncKeyState(VK_UP) & 0x8001)
		{
			gPlayer._y--;
		}
		// �Ʒ��� ����Ű.
		if (GetAsyncKeyState(VK_DOWN) & 0x8001)
		{
			gPlayer._y++;
		}

		//-------------------------------------------------------------
		// �÷��̾� �̵� �ݰ� ����.
		// ���� ȭ�鿡�� �÷��̾ �̵� ������ ������ �����Ѵ�.
		//-------------------------------------------------------------

		gPlayer._x = max(gPlayer._x, 0);
		gPlayer._x = min(gPlayer._x, 79);
		gPlayer._y = max(gPlayer._y, 0);
		gPlayer._y = min(gPlayer._y, 23);

		// ��Ʈ�� Ű. (�̻��� Ű)
		if (GetAsyncKeyState(VK_CONTROL))
		{
			/*
			_Missiles[_MissileCount].X = _Player.X;
			_Missiles[_MissileCount].Y = _Player.Y - 1;
			_Missiles[_MissileCount].Visible = 1;

			_MissileCount++;*/
		}

		// ESC Ű. (�Ͻ�����)
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
		Monster_Update();
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