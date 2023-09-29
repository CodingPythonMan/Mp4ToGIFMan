#pragma once
#include "SceneBase.h"

enum class SceneType
{
	TITLE,
	GAME,
	CLEAR,
	GAMEOVER,
};

class SceneManager
{
public:
	int Run();
	void LoadScene(SceneType sceneType);
	
	static SceneManager* GetInstance(void)
	{
		static SceneManager sceneManager;
		return &sceneManager;
	}

private:
	SceneManager();
	~SceneManager();

	SceneBase* _Scene;
};

