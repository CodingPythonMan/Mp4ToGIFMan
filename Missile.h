#pragma once

//--------------------------------------------------------------------
// 미사일 구조체 선언
//--------------------------------------------------------------------
struct _Missile
{
	int X;
	int Y;

	int Visible;
};


//--------------------------------------------------------------------
// 미사일 선언
//--------------------------------------------------------------------
_Missile _Missiles[30];


//--------------------------------------------------------------------
// 현재 미사일 수
//--------------------------------------------------------------------
int _MissileCount = 0;
