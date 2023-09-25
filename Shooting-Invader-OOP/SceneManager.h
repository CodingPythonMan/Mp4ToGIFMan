#pragma once
#include "SceneBase.h"

class SceneManager
{
public:
	void Run();
	void LoadScene();

private:
	SceneBase* _Scene;
};

