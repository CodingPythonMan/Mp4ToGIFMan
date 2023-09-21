#include "Player.h"
#include "Render.h"
#include "Missile.h"

//--------------------------------------------------------------------
// �÷��̾� �ν��Ͻ� ����, (1�ο� �̴� �ϳ��� ����)
//--------------------------------------------------------------------
PLAYER gPlayer;

void Player_Initial(void)
{
	//-------------------------------------------------------------------
	// �÷��̾� ���� ������ �ʱ�ȭ.
	// HP : 3 
	// 39,19 ��ġ���� ���� ��.
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
	// �÷��̾� �̵� �ݰ� ����.
	// ���� ȭ�鿡�� �÷��̾ �̵� ������ ������ �����Ѵ�.
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
	// �÷��̾� �̵� �ݰ� ����.
	// ���� ȭ�鿡�� �÷��̾ �̵� ������ ������ �����Ѵ�.
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
	// �ǰ�ó���� �׻� �ǰ� �־�� ��.
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