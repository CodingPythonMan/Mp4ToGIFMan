#include <windows.h>
#include "SceneGameOver.h"
#include "ObjectManager.h"
#include "ScreenBuffer.h"

SceneGameOver::SceneGameOver() : _firstDraw(false)
{
	ObjectManager::GetInstance()->ClearList();
}

int SceneGameOver::Update()
{
	if (GetAsyncKeyState(0x51) & 0x8001)
	{
		return false;
	}

	if (!_firstDraw)
	{
		Render();
		_firstDraw = true;
	}

	return true;
}

void SceneGameOver::Render()
{
	ScreenBuffer* screenBuffer = ScreenBuffer::GetInstance();

	screenBuffer->Clear();

	screenBuffer->StringSet(19, 2, "������������������������������������������������������");
	screenBuffer->StringSet(19, 3, "��        Game Over        ��");
	screenBuffer->StringSet(19, 4, "������������������������������������������������������");
	screenBuffer->StringSet(30, 22, "Q Button is quit.");

	screenBuffer->Flip();
}