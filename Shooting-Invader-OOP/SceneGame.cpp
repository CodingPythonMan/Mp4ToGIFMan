#include "SceneGame.h"
#include "DataReader.h"
#include "MonsterObject.h"
#include "ScreenBuffer.h"
#include "ObjectManager.h"

SceneGame::SceneGame()
{
	presentStage = 1;
	SetMonster();
}

int SceneGame::Update()
{
	ScreenBuffer* screenBuffer = ScreenBuffer::GetInstance();
	screenBuffer->Clear();

	ObjectManager::GetInstance()->Update();
	ObjectManager::GetInstance()->Render();

	screenBuffer->Flip();

	return true;
}

void SceneGame::SetMonster()
{
	StageInfo* stageInfo = DataReader::GetInstance()->GetStage(presentStage);

	for ( ; stageInfo->_monsterInfoPtr != nullptr; ++stageInfo)
	{
		int movePattern = stageInfo->_monsterInfoPtr->_movePattern;
		MovePatternInfo* movePatternInfo = DataReader::GetInstance()->GetMovePattern(movePattern);
		MonsterObject* monsterObject = new MonsterObject(stageInfo->_x, stageInfo->_y,
			stageInfo->_monsterInfoPtr->_moveCycle, stageInfo->_monsterInfoPtr->_shape,
			stageInfo->_monsterInfoPtr->_hp, stageInfo->_monsterInfoPtr->_coolTime,
			stageInfo->_monsterInfoPtr->_misslieSpeed,
			movePatternInfo->_dX, movePatternInfo->_dY, movePatternInfo->_move);
	}
}