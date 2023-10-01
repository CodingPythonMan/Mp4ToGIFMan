#pragma once

#define LINE_MAX_SIZE 200

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
	int _coolTime;
	int _moveCycle;
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

class DataReader
{
public:
	static DataReader* GetInstance()
	{
		static DataReader dataReader;
		return &dataReader;
	}

	StageInfo* GetStage(int stage);
	MovePatternInfo* GetMovePattern(int movePattern);

private:
	DataReader();
	~DataReader();

	void ReadMovePattern();
	void ReadMonster();
	int ReadStage();

private:
	MovePatternInfo _MovePatterns[10];
	MonsterInfo _MonsterInfos[10];
	StageInfo _StageInfos[10][10];
	int _stageCount;
};

