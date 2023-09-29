#pragma once
#include "SceneBase.h"

//--------------------------------------------------------------------
// 무브 패턴 정보 구조체
//--------------------------------------------------------------------
struct MovePatternInfo {
	int _dX[20];
	int _dY[20];
	int _move;
};

//--------------------------------------------------------------------
// 몬스터 정보 구조체
//--------------------------------------------------------------------
struct MonsterInfo {
	int _movePattern;
	char _shape;
	int _hp;
};

//--------------------------------------------------------------------
// 스테이지 구조체 선언
//--------------------------------------------------------------------
struct StageInfo
{
	MonsterInfo* _monsterInfoPtr;
	int _x;
	int _y;
};

class SceneGame : public SceneBase
{
public:
	SceneGame();

	int Update();
	void Render();

private:
	void DataReadMovePattern();

private:
	MovePatternInfo MovePatterns[10];
	MonsterInfo MonsterInfos[10];
	StageInfo StageInfos[10][10];
};