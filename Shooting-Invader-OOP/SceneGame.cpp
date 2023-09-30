#include "SceneGame.h"
#include "DataReader.h"
#include "MonsterObject.h"

SceneGame::SceneGame()
{
	presentStage = 1;
}

int SceneGame::Update()
{
	return true;
}

void SceneGame::Render()
{
}

void SceneGame::SetMonster()
{
	StageInfo* stageInfo = DataReader::GetInstance()->GetStage(presentStage);


}