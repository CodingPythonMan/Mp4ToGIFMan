#pragma once
#include "BaseObject.h"

class MissileObject : public BaseObject
{
public:
	MissileObject(int x, int y, char shape, ObjectType objectType, int misslieSpeed);

	// BaseObject을(를) 통해 상속됨
	void Update();
	void Render();
	void OnCollision(BaseObject* target);

private:
	int _missileSpeed;
	char _shape;
	ObjectType _attackType;

	int _time;
};