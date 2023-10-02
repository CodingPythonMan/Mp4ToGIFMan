#pragma once
#include "BaseObject.h"

#define PLAYER_MISSILE_SPEED 20
#define PLAYER_X 39
#define PLAYER_Y 19
#define PLAYER_HP 3

class PlayerObject : public BaseObject
{
public:
	PlayerObject();

	bool Update();
	void Render();
	void OnCollision();

private:
	int _hp;
};