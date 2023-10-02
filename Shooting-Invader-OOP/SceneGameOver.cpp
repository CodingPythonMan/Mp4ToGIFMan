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

	screenBuffer->StringSet(19, 2, "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	screenBuffer->StringSet(19, 3, "弛        Game Over        弛");
	screenBuffer->StringSet(19, 4, "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	screenBuffer->StringSet(30, 22, "Q Button is quit.");

	screenBuffer->Flip();
}