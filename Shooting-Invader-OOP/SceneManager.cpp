#include <windows.h>
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneGameOver.h"

SceneManager::SceneManager()
{
	_Scene = new SceneTitle();
}

SceneManager::~SceneManager()
{
}

int SceneManager::Run()
{
	unsigned int tick = 0;
	unsigned int curTime = timeGetTime();
	unsigned int ourTime = curTime;
	unsigned int frameTime = curTime;
	int FrameCount = 0;

	bool skipDraw = false;

	int result = _Scene->Update();

	FrameCount++;
	// Cal
	curTime = timeGetTime();
	tick = curTime - ourTime;
	ourTime += WAIT;

	// Skip
	if (tick <= WAIT)
	{
		Sleep(WAIT - tick);
		skipDraw = false;
	}
	else
		skipDraw = true;

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