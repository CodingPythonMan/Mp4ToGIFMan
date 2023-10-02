#pragma once
#include "SceneBase.h"
#include "PlayerObject.h"

#define MAX_STAGE 3

class SceneGame : public SceneBase
{
public:
	SceneGame();

	int Update();

private:
	void SetNextStage();
	void SetMonster();

	int _presentStage;
	PlayerObject* _player;
};