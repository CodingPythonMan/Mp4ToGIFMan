#include "SceneManager.h"
#include "SceneTitle.h"

SceneManager::SceneManager()
{
	_Scene = new SceneTitle();
}

SceneManager::~SceneManager()
{
}

void SceneManager::Run()
{
	
}

void SceneManager::LoadScene(SceneType sceneType)
{
	delete _Scene;

	switch (sceneType)
	{
	case SceneType::TITLE:

		break;
	case SceneType::GAME:

		break;
	case SceneType::PAUSE:

		break;

	case SceneType::CLEAR:

		break;
	case SceneType::GAMEOVER:
		break;
	}
}