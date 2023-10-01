#pragma once
#include "BaseObject.h"

class MissileObject : public BaseObject
{
public:
	MissileObject(int x, int y, char shape, bool player);

	// BaseObject을(를) 통해 상속됨
	bool Update();
	void Render();

private:
	char _shape;
	bool _player;
};