#pragma once

enum class SceneType {
	TITLE,
	STAGE,
	GAMEOVER,
	CLEAR,
};

extern SceneType gSceneType;

//--------------------------------------------------------------------
// Title �׸��� �Լ�
//--------------------------------------------------------------------
void Scene_DrawTitle();