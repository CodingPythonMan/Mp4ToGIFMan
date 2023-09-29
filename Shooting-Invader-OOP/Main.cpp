#include "SceneManager.h"

#pragma comment(lib, "winmm.lib")

int main()
{
	while (1)
	{
		if (!SceneManager::GetInstance()->Run())
		{
			return 0;
		}
	}
}