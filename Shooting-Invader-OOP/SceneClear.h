#pragma once
#include "SceneBase.h"

class SceneClear : public SceneBase
{
public:
	SceneClear();

	int Update();
	void Render();

private:
	bool _firstDraw;
};

