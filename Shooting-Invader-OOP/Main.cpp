#include "ObjectManager.h"
#include "ScreenBuffer.h"
#include "windows.h"

int main()
{
	ObjectManager* objectManager = ObjectManager::GetInstance();
	ScreenBuffer* screenBuffer = ScreenBuffer::GetInstance();

	while (1)
	{
		objectManager->Update();
		objectManager->Render();

		screenBuffer->Flip();

		Sleep(50);
	}
}