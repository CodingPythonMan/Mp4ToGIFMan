#pragma once
#include "BaseObject.h"

#define PLAYER_MISSILE_SPEED 12
#define PLAYER_X 39
#define PLAYER_Y 19
#define PLAYER_HP 3

class PlayerObject : public BaseObject
{
public:
	PlayerObject();

	void Update();
	void Render();
	void OnCollision(BaseObject* target);

	bool IsDead();

private:
	int _hp;
	char _shape;
};