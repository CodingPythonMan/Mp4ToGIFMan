#include "MonsterObject.h"
#include "ObjectManager.h"
#include "ScreenBuffer.h"

MonsterObject::MonsterObject(int x, int y, int moveCycle, char shape, int hp,
	int coolTime, int* dX, int* dY, int move) : _moveCycle(moveCycle), _shape(shape),
	_hp(hp), _coolTime(coolTime), _dX(dX), _dY(dY), _move(move)
{
	_X = x;
	_Y = y;
	_visible = 1;

	ObjectManager::GetInstance()->CreateObject(this);
}

bool MonsterObject::Update()
{
	return false;
}

bool MonsterObject::Render()
{
	ScreenBuffer::GetInstance()->SpriteDraw(_X, _Y, _shape);

	return false;
}
