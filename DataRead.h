#pragma once

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
	MovePatternInfo* _movePatternPtr;
	char _shape;
	int _hp;
};

//--------------------------------------------------------------------
// 몬스터 정보 배열
//--------------------------------------------------------------------
extern MonsterInfo* gMonsterInfos[10];

//--------------------------------------------------------------------
// 파일 읽어 메모리에 넣기
//--------------------------------------------------------------------
char* Data_Read(const char* data);

//--------------------------------------------------------------------
// 무브 패턴 파일 읽어 메모리에 넣기
//--------------------------------------------------------------------
void MovePattern_Read(void);

//--------------------------------------------------------------------
// 몬스터 파일 읽어 메모리에 넣기
//--------------------------------------------------------------------
void Monster_Read(void);