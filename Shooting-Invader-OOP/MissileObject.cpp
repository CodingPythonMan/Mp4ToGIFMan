#include "MissileObject.h"

MissileObject::MissileObject(int x, int y, char shape, bool player)
{
	_X = x;
	_Y = y;
	_shape = shape;
	_player = player;
}

bool MissileObject::Update()
{
	if (_player)
	{
		
	}
	else
	{

	}

	return false;
}

void MissileObject::Render()
{
}
