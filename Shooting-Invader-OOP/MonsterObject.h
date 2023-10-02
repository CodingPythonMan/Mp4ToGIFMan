#pragma once
#include "BaseObject.h"

class MonsterObject : public BaseObject
{
public:
	MonsterObject(int x, int y, int moveCycle, char shape, int hp,
	int coolTime, int bulletSpeed, int* dX, int* dY, int move);

	void Update();
	void Render();
	void OnCollision(BaseObject* target);

private:
	int _moveCycle;
	char _shape;
	int _hp;
	int _coolTime;
	int _missileSpeed;

	int* _dX;
	int* _dY;
	int _move;

	int _time;
	int _presentMove;
	int _attackTime;
};