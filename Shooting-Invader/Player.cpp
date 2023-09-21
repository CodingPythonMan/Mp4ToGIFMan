#include "Player.h"
#include "Render.h"
#include "Missile.h"

//--------------------------------------------------------------------
// 플레이어 인스턴스 선언, (1인용 이니 하나만 하자)
//--------------------------------------------------------------------
PLAYER gPlayer;

void Player_Initial(void)
{
	//-------------------------------------------------------------------
	// 플레이어 최초 데이터 초기화.
	// HP : 3 
	// 39,19 위치에서 시작 함.
	//-------------------------------------------------------------------
	gPlayer._hp = 3;
	gPlayer._visible = true;

	gPlayer._x = 39;
	gPlayer._y = 19;
}

void Player_xMove(int move)
{
	gPlayer._x += move;
	//-------------------------------------------------------------
	// 플레이어 이동 반경 제한.
	// 게임 화면에서 플레이어가 이동 가능한 구역을 제한한다.
	//-------------------------------------------------------------

	if (gPlayer._x < 0)
	{
		gPlayer._x = 0;
	}
	if (gPlayer._x > 79)
	{
		gPlayer._x = 79;
	}
}

void Player_yMove(int move)
{
	gPlayer._y += move;
	//-------------------------------------------------------------
	// 플레이어 이동 반경 제한.
	// 게임 화면에서 플레이어가 이동 가능한 구역을 제한한다.
	//-------------------------------------------------------------

	if (gPlayer._y < 0)
	{
		gPlayer._y = 0;
	}
	if (gPlayer._y > 23)
	{
		gPlayer._y = 23;
	}
}

void Player_MissileAttack()
{
	if (gPlayer._attackCoolTime / PLAYER_ATTACK_PERIOD > 1)
	{
		Missile_Create(gPlayer._x, gPlayer._y, '|', true);
		gPlayer._attackCoolTime = 0;
	}
}

bool Player_Update(void)
{
	// 피격처리는 항상 되고 있어야 함.
	for (int i = 0; i < MAX_MISSILE_COUNT; i++)
	{
		if (gMissiles[i]._visible && gMissiles[i]._player == false)
		{
			if (gPlayer._visible && gPlayer._x == gMissiles[i]._x && gPlayer._y == gMissiles[i]._y)
			{
				gMissiles[i]._visible = 0;
				gPlayer._hp--;

				if (gPlayer._hp == 0)
				{
					return false;
				}
			}
		}
	}

	gPlayer._attackCoolTime++;

	return true;
}

void Player_Draw(void)
{
	Sprite_Draw(gPlayer._x, gPlayer._y, '#');
}