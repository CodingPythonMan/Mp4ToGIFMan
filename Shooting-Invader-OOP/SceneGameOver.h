#pragma once
#include "SceneBase.h"

class SceneGameOver : public SceneBase
{
public:
	SceneGameOver();

	int Update();
	void Render();

private:
	bool _firstDraw;
};

