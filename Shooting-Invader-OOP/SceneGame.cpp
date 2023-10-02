#include <stdio.h>
#include "SceneGame.h"
#include "DataReader.h"
#include "MonsterObject.h"
#include "ScreenBuffer.h"
#include "ObjectManager.h"
#include "SceneManager.h"

SceneGame::SceneGame()
{
	_presentStage = 1;
	SetMonster();
	_player = new PlayerObject();
	ObjectManager::GetInstance()->CreateObject(_player);
}

int SceneGame::Update()
{
	ScreenBuffer* screenBuffer = ScreenBuffer::GetInstance();
	screenBuffer->Clear();

	ObjectManager::GetInstance()->Update();

	if (_player->IsDead())
	{
		SceneManager::GetInstance()->LoadScene(SceneType::GAMEOVER);
	}

	if (MonsterObject::_monsterCount <= 0)
	{
		if (_presentStage == MAX_STAGE)
		{
			SceneManager::GetInstance()->LoadScene(SceneType::CLEAR);
		}

		SetNextStage();
	}

	ObjectManager::GetInstance()->Render();

	screenBuffer->Flip();
	printf("\nHP : %d", _player->DisplayHP());

	return true;
}

void SceneGame::SetNextStage()
{
	_presentStage++;
	MonsterObject::_monsterCount = 0;
	ObjectManager::GetInstance()->ClearList();
	_player = _player->LoadStatusByPreviousStage();
	SetMonster();
}

void SceneGame::SetMonster()
{
	StageInfo* stageInfo = DataReader::GetInstance()->GetStage(_presentStage);

	for (; stageInfo->_monsterInfoPtr != nullptr; ++stageInfo)
	{
		int movePattern = stageInfo->_monsterInfoPtr->_movePattern;
		MovePatternInfo* movePatternInfo = DataReader::GetInstance()->GetMovePattern(movePattern);
		MonsterObject* monsterObject = new MonsterObject(stageInfo->_x, stageInfo->_y,
			stageInfo->_monsterInfoPtr->_moveCycle, stageInfo->_monsterInfoPtr->_shape,
			stageInfo->_monsterInfoPtr->_hp, stageInfo->_monsterInfoPtr->_coolTime,
			stageInfo->_monsterInfoPtr->_misslieSpeed,
			movePatternInfo->_dX, movePatternInfo->_dY, movePatternInfo->_move);

		MonsterObject::_monsterCount++;
		ObjectManager::GetInstance()->CreateObject(monsterObject);
	}
}