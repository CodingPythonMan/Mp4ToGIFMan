#pragma once
#include "BaseObject.h"

class MissileObject : public BaseObject
{
public:
	MissileObject(int x, int y, char shape, bool player);

	// BaseObject��(��) ���� ��ӵ�
	bool Update();
	void Render();

private:
	char _shape;
	bool _player;
};