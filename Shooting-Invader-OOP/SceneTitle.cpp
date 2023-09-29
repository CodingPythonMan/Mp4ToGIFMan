#include "SceneTitle.h"
#include "ScreenBuffer.h"
#include "SceneManager.h"
#include <Windows.h>

SceneTitle::SceneTitle()
{
	timeBeginPeriod(1);
	ScreenBuffer::GetInstance()->ConsoleInit();
}

int SceneTitle::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::GetInstance()->LoadScene(SceneType::GAME);
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
	{
		return false;
	}

	return true;
}

void SceneTitle::Render()
{
	ScreenBuffer* screenBuffer = ScreenBuffer::GetInstance();

	screenBuffer->Clear();

	screenBuffer->StringSet(19, 2, "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	screenBuffer->StringSet(19, 3, "弛      Abyss Invader      弛");
	screenBuffer->StringSet(19, 4, "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	screenBuffer->StringSet(30, 20, "Press Enter For Start!");
	screenBuffer->StringSet(30, 22, "ESC Button is quit.");

	screenBuffer->Flip();
}