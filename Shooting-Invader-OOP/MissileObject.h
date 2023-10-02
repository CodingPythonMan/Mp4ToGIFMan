#pragma once
#include "BaseObject.h"

class MissileObject : public BaseObject
{
public:
	MissileObject(int x, int y, char shape, ObjectType objectType, int misslieSpeed);

	// BaseObject��(��) ���� ��ӵ�
	bool Update();
	void Render();
	void OnCollision();

private:
	int _missileSpeed;
	char _shape;
	ObjectType _attackType;

};