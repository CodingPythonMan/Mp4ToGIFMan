#pragma once

enum class SceneType {
	TITLE,
	STAGE,
	GAMEOVER,
	CLEAR,
};

extern SceneType gSceneType;

//--------------------------------------------------------------------
// Title 그리는 함수
//--------------------------------------------------------------------
void DrawTitle();