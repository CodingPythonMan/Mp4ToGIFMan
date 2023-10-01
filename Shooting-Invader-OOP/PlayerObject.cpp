#include <windows.h>
#include "PlayerObject.h"

bool PlayerObject::Update()
{
	// 콘트롤 키. (미사일 키)
	if (GetAsyncKeyState(VK_CONTROL))
	{

	}

	return false;
}

void PlayerObject::Render()
{
}
