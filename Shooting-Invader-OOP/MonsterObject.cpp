#include "MonsterObject.h"
#include "ObjectManager.h"
#include "ScreenBuffer.h"
#include "MissileObject.h"

int MonsterObject::_monsterCount = 0;

MonsterObject::MonsterObject(int x, int y, int moveCycle, char shape, int hp,
	int coolTime, int missileSpeed, int* dX, int* dY, int move) : _moveCycle(moveCycle), _shape(shape),
	_hp(hp), _coolTime(coolTime), _missileSpeed(missileSpeed), _dX(dX), _dY(dY), _move(move)
{
	_X = x;
	_Y = y;
	_ObjectType = ObjectType::Monster;
	_time = 0;
	_presentMove = 0;
	_attackTime = 0;
}

void MonsterObject::Update()
{
	// 이동 및 없어져야하는지 체크
	_time++;
	_attackTime++;

	// 움직일 때만 Render
	if (_time > _moveCycle)
	{
		_X += _dX[_presentMove % _move];
		_Y += _dY[_presentMove % _move];

		_presentMove++;

		Render();

		_time = 0;
	}
	
	// Cooltime 보다 넘었다면 Bullet 발사
	if (_attackTime > _coolTime)
	{
		MissileObject* missileObject = new MissileObject(_X, _Y+1, 'O', ObjectType::Monster,
			_missileSpeed);

		ObjectManager::GetInstance()->CreateObject(missileObject);

		_attackTime = 0;
	}
}

void MonsterObject::Render()
{
	ScreenBuffer::GetInstance()->SpriteDraw(_X, _Y, _shape);
}

void MonsterObject::OnCollision(BaseObject* target)
{
	if (target->GetObjectType() == ObjectType::Missile && ((MissileObject*)target)->GetAttackType() == ObjectType::Player)
	{
		_hp--;
	}

	if (_hp <= 0)
	{
		_monsterCount--;
		ObjectManager::GetInstance()->AddDeleteList(this);
	}
}
