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
	_time = 0;
}

void MissileObject::Update()
{
	_time++;

	if (_time % _missileSpeed == 0)
	{
		if (_attackType == ObjectType::Player)
		{
			_Y--;
		}
		else if (_attackType == ObjectType::Monster)
		{
			_Y++;
		}

		// 경계 밖으로 나가면 사라진다.
		if (_X < 0 || _X > SCREEN_WIDTH-2 || _Y < 0 || _Y > SCREEN_HEIGHT-1)
		{
			ObjectManager::GetInstance()->AddDeleteList(this);
		}

		_time = 0;
	}
}

void MissileObject::Render()
{
	ScreenBuffer::GetInstance()->SpriteDraw(_X, _Y, _shape);
}

void MissileObject::OnCollision(BaseObject* target)
{
	ObjectManager::GetInstance()->AddDeleteList(this);
}

ObjectType MissileObject::GetAttackType()
{
	return _attackType;
}
