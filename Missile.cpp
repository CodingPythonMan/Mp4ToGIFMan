#include "Missile.h"
#include "Render.h"

Missile gMissiles[MAX_MISSILE_COUNT];
int gMissileTimeCycle = 0;

void Missile_Create(int x, int y, char ch, bool player)
{
	for (int i = 0; i < MAX_MISSILE_COUNT; i++)
	{
		if (x == gMissiles[i]._x && y == gMissiles[i]._y)
			break;

		if (0 == gMissiles[i]._visible)
		{
			gMissiles[i]._x = x;
			gMissiles[i]._y = y;
			gMissiles[i]._shape = ch;
			gMissiles[i]._player = player;
			gMissiles[i]._visible = 1;
			break;
		}
	}
}

void Missile_Update()
{
	if (gMissileTimeCycle % MISSILE_MOVE_CYCLE == 0)
	{
		for (int i = 0; i < MAX_MISSILE_COUNT; i++)
		{
			if (gMissiles[i]._x < 0 || gMissiles[i]._x > 79 || gMissiles[i]._y < 0 || gMissiles[i]._y > 23)
			{
				gMissiles[i]._visible = 0;
			}

			if (gMissiles[i]._visible)
			{
				if (true == gMissiles[i]._player)
					gMissiles[i]._y--;
				else
					gMissiles[i]._y++;
			}
		}
		gMissileTimeCycle = 0;
	}
	gMissileTimeCycle++;
}

void Missile_Draw()
{
	for (int i = 0; i < MAX_MISSILE_COUNT; i++)
	{
		if (gMissiles[i]._visible)
		{
			Sprite_Draw(gMissiles[i]._x, gMissiles[i]._y, gMissiles[i]._shape);
		}
	}
}