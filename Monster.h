#pragma once

#define MAX_MONSTER_COUNT 20
#define MONSTER_MOVE_CYCLE 20
#define MONSTER_ATTACK_PERIOD 2

//--------------------------------------------------------------------
// 몬스터 구조체 선언
//--------------------------------------------------------------------
struct Monster
{
	int _x;
	int _y;
	int _movePattern;
	int _moveCycle;
	char _shape;
	int _hp;
	int _attackCoolTime;

	int _visible;
};

//--------------------------------------------------------------------
// 몬스터 셋팅
//--------------------------------------------------------------------
void Monster_Set(int presentStage);

//--------------------------------------------------------------------
// 몬스터 업데이트
//--------------------------------------------------------------------
bool Monster_Update();

//--------------------------------------------------------------------
// 몬스터 그리기
//--------------------------------------------------------------------
void Monster_Draw();