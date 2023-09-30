#pragma once
#include "SceneBase.h"

class SceneGame : public SceneBase
{
public:
	SceneGame();

	int Update();
	void Render();

private:
	void SetMonster();

private:
	int presentStage;
};