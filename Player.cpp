#include "Player.h"
#include "Render.h"

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

void Player_Update(void)
{

}

void Player_Draw(void)
{
	Sprite_Draw(gPlayer._x, gPlayer._y, '#');
}