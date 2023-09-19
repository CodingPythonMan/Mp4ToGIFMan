#include "Monster.h"
#include "DataRead.h"
#include "Render.h"
#include "Missile.h"

Monster gMonsters[MAX_MONSTER_COUNT];
int gMonsterCount = 0;
int gTimeCycle = 0;

void Monster_Set(int presentStage)
{
	// 1 낮추어서 Index 맞추기
	presentStage -= 1;
	gMonsterCount = 0;

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

		gMonsterCount++;
	}
}

bool Monster_Update()
{
	// 움직임
	if (gTimeCycle % MONSTER_MOVE_CYCLE == 0)
	{
		for (int i = 0; i < MAX_MONSTER_COUNT; i++)
		{
			if (gMonsters[i]._visible)
			{
				gMonsters[i]._x += gMovePatterns[gMonsters[i]._movePattern]._dX[gMonsters[i]._moveCycle];
				gMonsters[i]._y += gMovePatterns[gMonsters[i]._movePattern]._dY[gMonsters[i]._moveCycle];

				gMonsters[i]._moveCycle++;
				gMonsters[i]._moveCycle %= gMovePatterns[gMonsters[i]._movePattern]._move;

				if (gMonsters[i]._attackCoolTime / MONSTER_ATTACK_PERIOD > 1)
				{
					Missile_Create(gMonsters[i]._x, gMonsters[i]._y, 'o', false);
					gMonsters[i]._attackCoolTime = 0;
				}

				gMonsters[i]._attackCoolTime++;
			}
		}
		gTimeCycle = 0;
	}

	// 피격처리는 항상 되고 있어야 함.
	for (int i = 0; i < MAX_MISSILE_COUNT; i++)
	{
		if (gMissiles[i]._visible && gMissiles[i]._player)
		{
			for (int j = 0; j < MAX_MONSTER_COUNT; j++)
			{
				if (gMonsters[j]._visible && gMonsters[j]._x == gMissiles[i]._x && gMonsters[j]._y == gMissiles[i]._y)
				{
					gMissiles[i]._visible = 0;
					gMonsters[j]._hp--;

					if (gMonsters[j]._hp == 0)
					{
						gMonsters[j]._visible = 0;
						gMonsterCount--;
					}
				}
			}
		}
	}

	if (gMonsterCount == 0)
		return false;

	gTimeCycle++;

	return true;
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