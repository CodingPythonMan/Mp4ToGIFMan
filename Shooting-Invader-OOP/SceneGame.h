#pragma once
#include "SceneBase.h"

//--------------------------------------------------------------------
// ���� ���� ���� ����ü
//--------------------------------------------------------------------
struct MovePatternInfo {
	int _dX[20];
	int _dY[20];
	int _move;
};

//--------------------------------------------------------------------
// ���� ���� ����ü
//--------------------------------------------------------------------
struct MonsterInfo {
	int _movePattern;
	char _shape;
	int _hp;
};

//--------------------------------------------------------------------
// �������� ����ü ����
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