#pragma once
#include "SceneBase.h"

class SceneGame : public SceneBase
{
public:
	SceneGame();

	int Update();

private:
	void SetMonster();

private:
	int presentStage;
};