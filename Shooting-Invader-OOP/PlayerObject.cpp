#include <windows.h>
#include "PlayerObject.h"
#include "MissileObject.h"
#include "ScreenBuffer.h"

PlayerObject::PlayerObject()
{
	_ObjectType = ObjectType::Player;
	
	_X = PLAYER_X;
	_Y = PLAYER_Y;
	_hp = PLAYER_HP;
}

bool PlayerObject::Update()
{
	// ���� ����Ű.
	if (GetAsyncKeyState(VK_LEFT))
	{
		_X--;
	}
	// ������ ����Ű.
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_X++;
	}
	// ���� ����Ű.
	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		_Y--;
	}
	// �Ʒ��� ����Ű.
	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		_Y++;
	}

	// ��Ʈ�� Ű. (�̻��� Ű)
	if (GetAsyncKeyState(VK_CONTROL))
	{
		MissileObject* missileObject = new MissileObject(_X, _Y + 1, '|', ObjectType::Player
		, PLAYER_MISSILE_SPEED);
	}

	return false;
}

void PlayerObject::Render()
{

}

void PlayerObject::OnCollision()
{

}