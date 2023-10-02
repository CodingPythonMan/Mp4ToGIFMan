#include "MissileObject.h"
#include "ObjectManager.h"
#include "ScreenBuffer.h"

MissileObject::MissileObject(int x, int y, char shape, ObjectType objectType, int missileSpeed)
{
	_X = x;
	_Y = y;
	_shape = shape;
	_attackType = objectType;
	_missileSpeed = missileSpeed;
	_ObjectType = ObjectType::Missile;

	ObjectManager::GetInstance()->CreateObject(this);
}

bool MissileObject::Update()
{
	if (_attackType == ObjectType::Player)
	{
		_Y--;
	}
	else if(_attackType == ObjectType::Monster)
	{
		_Y++;
	}

		

	return false;
}

void MissileObject::Render()
{
	ScreenBuffer::GetInstance()->SpriteDraw(_X, _Y, _shape);
}

void MissileObject::OnCollision()
{
}
