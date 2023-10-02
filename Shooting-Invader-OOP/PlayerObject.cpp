#include <windows.h>
#include "PlayerObject.h"
#include "MissileObject.h"
#include "ScreenBuffer.h"
#include "ObjectManager.h"

PlayerObject::PlayerObject()
{
	_ObjectType = ObjectType::Player;
	
	_X = PLAYER_X;
	_Y = PLAYER_Y;
	_hp = PLAYER_HP;
	_shape = '#';
	_attackCoolTime = 0;
	_moveCoolTime = 0;
}

void PlayerObject::Update()
{
	_attackCoolTime++;
	_moveCoolTime++;

	if (_moveCoolTime > MOVE_COOLTIME)
	{
		// 왼쪽 방향키.
		if (GetAsyncKeyState(VK_LEFT))
		{
			_X--;
		}
		// 오른쪽 방향키.
		if (GetAsyncKeyState(VK_RIGHT))
		{
			_X++;
		}
		// 위쪽 방향키.
		if (GetAsyncKeyState(VK_UP) & 0x8001)
		{
			_Y--;
		}
		// 아래쪽 방향키.
		if (GetAsyncKeyState(VK_DOWN) & 0x8001)
		{
			_Y++;
		}

		_moveCoolTime = 0;
	}

	// 콘트롤 키. (미사일 키)
	if (GetAsyncKeyState(VK_CONTROL))
	{
		if (_attackCoolTime > ATTACK_COOLTIME)
		{
			MissileObject* missileObject = new MissileObject(_X, _Y - 1, '|', ObjectType::Player
				, PLAYER_MISSILE_SPEED);
			ObjectManager::GetInstance()->CreateObject(missileObject);

			_attackCoolTime = 0;
		}
	}
}

void PlayerObject::Render()
{
	ScreenBuffer::GetInstance()->SpriteDraw(_X, _Y, _shape);
}

void PlayerObject::OnCollision(BaseObject* target)
{
	if((target->GetObjectType() == ObjectType::Missile && ((MissileObject*)target)->GetAttackType() == ObjectType::Monster)
		|| target->GetObjectType() == ObjectType::Monster)
		_hp--;
}

bool PlayerObject::IsDead()
{
	if (_hp > 0)
		return false;

	return true;
}

PlayerObject* PlayerObject::LoadStatusByPreviousStage()
{
	PlayerObject* object = new PlayerObject();
	object->_hp = _hp;

	ObjectManager::GetInstance()->CreateObject(object);

	return object;
}

int PlayerObject::DisplayHP()
{
	return _hp;
}