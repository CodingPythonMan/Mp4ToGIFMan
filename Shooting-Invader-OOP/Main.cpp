#include "ObjectManager.h"
#include "ScreenBuffer.h"
#include "windows.h"

int main()
{
	while (1)
	{
		ObjectManager::GetInstance()->Update();
		ObjectManager::GetInstance()->Render();

		ScreenBuffer::GetInstance()->Flip();

		Sleep(50);
	}
}