#include <Windows.h>
#include "Console.h"
#include "Game.h"
#include "Scene.h"
#include "Player.h"

void Game_KeyProcess(void)
{
	switch (gSceneType)
	{
	case SceneType::STAGE:
		// ���� ����Ű.
		if (GetAsyncKeyState(VK_LEFT))
		{
			gPlayer._X -= 1;
		}
		// ������ ����Ű.
		if (GetAsyncKeyState(VK_RIGHT))
		{
			_Player.X += 1;
		}
		// ���� ����Ű.
		if (GetAsyncKeyState(VK_UP) & 0x8001)
		{
			_Player.Y--;
		}
		// �Ʒ��� ����Ű.
		if (GetAsyncKeyState(VK_DOWN) & 0x8001)
		{
			_Player.Y++;
		}

		//-------------------------------------------------------------
		// �÷��̾� �̵� �ݰ� ����.
		// ���� ȭ�鿡�� �÷��̾ �̵� ������ ������ �����Ѵ�.
		//-------------------------------------------------------------

		_Player.X = max(_Player.X, 0);
		_Player.X = min(_Player.X, 79);
		_Player.Y = max(_Player.Y, 0);
		_Player.Y = min(_Player.Y, 23);


		// ��Ʈ�� Ű. (�̻��� Ű)
		if (GetAsyncKeyState(VK_CONTROL))
		{
			_Missiles[_MissileCount].X = _Player.X;
			_Missiles[_MissileCount].Y = _Player.Y - 1;
			_Missiles[_MissileCount].Visible = 1;

			_MissileCount++;
		}

		// ESC Ű. (�Ͻ�����)
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
		{

		}
		break;
	}

	

}