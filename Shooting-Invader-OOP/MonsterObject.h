#pragma once
#include "BaseObject.h"

class MonsterObject : public BaseObject
{
public:
	MonsterObject(int x, int y, int moveCycle, char shape, int hp,
	int coolTime, int* dX, int* dY, int move);

	bool Update();
	void Render();

private:
	int _moveCycle;
	char _shape;
	int _hp;
	int _coolTime;

	int* _dX;
	int* _dY;
	int _move;

	int _time;
	int _presentMove;
	int _attackTime;
};