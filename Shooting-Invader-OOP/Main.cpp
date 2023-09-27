#include "SceneManager.h"

#pragma comment(lib, "winmm.lib")

int main()
{
	while (1)
	{
		SceneManager::GetInstance()->Run();
	}
}