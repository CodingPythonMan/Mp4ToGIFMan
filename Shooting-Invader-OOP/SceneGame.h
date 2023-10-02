#pragma once
#include "SceneBase.h"
#include "PlayerObject.h"

class SceneGame : public SceneBase
{
public:
	SceneGame();

	int Update();

private:
	void SetMonster();

private:
	int _presentStage;
	PlayerObject* _player;
};