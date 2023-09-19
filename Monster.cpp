#include "Monster.h"
#include "DataRead.h"
#include "Render.h"

Monster gMonsters[MAX_MONSTER_COUNT];
int gTimeCycle = 0;

void Monster_Set(int presentStage)
{
	// 1 낮추어서 Index 맞추기
	presentStage -= 1;

	for (int i = 0; i < MAX_MONSTER_COUNT; i++)
	{
		gMonsters[i]._visible = false;
	}

	for (int i = 0; gStageInfos[presentStage][i]._monsterInfoPtr != nullptr; i++)
	{
		gMonsters[i]._x = gStageInfos[presentStage][i]._x;
		gMonsters[i]._y = gStageInfos[presentStage][i]._y;
		gMonsters[i]._movePattern = gStageInfos[presentStage][i]._monsterInfoPtr->_movePattern;
		gMonsters[i]._shape = gStageInfos[presentStage][i]._monsterInfoPtr->_shape;
		gMonsters[i]._hp = gStageInfos[presentStage][i]._monsterInfoPtr->_hp;
		gMonsters[i]._visible = 1;
	}
}

void Monster_Update()
{
	if (gTimeCycle % MOVE_CYCLE == 0)
	{
		for (int i = 0; i < MAX_MONSTER_COUNT; i++)
		{
			if (gMonsters[i]._visible)
			{
				gMonsters[i]._x += gMovePatterns[gMonsters[i]._movePattern]._dX[gMonsters[i]._moveCycle];
				gMonsters[i]._y += gMovePatterns[gMonsters[i]._movePattern]._dY[gMonsters[i]._moveCycle];

				gMonsters[i]._moveCycle++;
				gMonsters[i]._moveCycle %= gMovePatterns[gMonsters[i]._movePattern]._move;
			}
		}
		gTimeCycle = 0;
	}
	gTimeCycle++;
}

void Monster_Draw()
{
	for (int i = 0; i < MAX_MONSTER_COUNT; i++)
	{
		if (gMonsters[i]._visible)
		{
			Sprite_Draw(gMonsters[i]._x, gMonsters[i]._y, gMonsters[i]._shape);
		}
	}
}