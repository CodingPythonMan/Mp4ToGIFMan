#pragma once
#include "BaseObject.h"

#define PLAYER_MISSILE_SPEED 12
#define ATTACK_COOLTIME 28
#define MOVE_COOLTIME 5
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
	PlayerObject* LoadStatusByPreviousStage();
	int DisplayHP();

private:
	int _hp;
	char _shape;
	int _attackCoolTime;
	int _moveCoolTime;
};