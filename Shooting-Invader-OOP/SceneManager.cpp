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
	int result = _Scene->Update();

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