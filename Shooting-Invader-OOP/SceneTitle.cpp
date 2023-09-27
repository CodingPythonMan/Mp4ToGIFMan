#include "SceneTitle.h"
#include "ScreenBuffer.h"
#include <Windows.h>

SceneTitle::SceneTitle()
{
	timeBeginPeriod(1);
	ScreenBuffer::GetInstance()->ConsoleInit();
}

void SceneTitle::Update()
{
	ScreenBuffer* screenBuffer = ScreenBuffer::GetInstance();

	screenBuffer->Clear();

	screenBuffer->StringSet(19, 2, "������������������������������������������������������");
	screenBuffer->StringSet(19, 3, "��      Abyss Invader      ��");
	screenBuffer->StringSet(19, 4, "������������������������������������������������������");
	screenBuffer->StringSet(30, 20, "Press Enter For Start!");
	screenBuffer->StringSet(30, 22, "ESC Button is quit.");

	screenBuffer->Flip();
}