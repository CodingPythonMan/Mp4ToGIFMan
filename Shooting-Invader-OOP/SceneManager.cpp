#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneGameOver.h"
#include <windows.h>

SceneManager::SceneManager()
{
	_Scene = new SceneTitle();
}

SceneManager::~SceneManager()
{
}

int SceneManager::Run()
{
	unsigned long delay = 0;
	unsigned long beforeTime = timeGetTime();
	int FrameCount = 0;
	DWORD Tick = timeGetTime();

	int result = _Scene->Update();

	FrameCount++;
	if (timeGetTime() - Tick >= 1000)
	{
		FrameCount = 0;
		Tick = timeGetTime();
	}

	// 프레임 조절
	if (delay < 20)
	{
		Sleep(20 - delay);
		beforeTime += 20;
		delay = timeGetTime() - beforeTime;
	}

	return result;
}

void SceneManager::LoadScene(SceneType sceneType)
{
	delete _Scene;

	switch (sceneType)
	{
	case SceneType::TITLE:
		_Scene = new SceneTitle();
		break;
	case SceneType::GAME:
		_Scene = new SceneGame();
		break;
	case SceneType::CLEAR:
		_Scene = new SceneClear();
		break;
	case SceneType::GAMEOVER:
		_Scene = new SceneGameOver();
		break;
	}
}