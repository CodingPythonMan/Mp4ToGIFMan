#include "Scene.h"
#include "Render.h"

SceneType gSceneType = SceneType::TITLE;

void Scene_DrawTitle()
{
	String_Set(19,2,"������������������������������������������������������");
	String_Set(19,3,"��      Abyss Invader      ��");
	String_Set(19,4,"������������������������������������������������������");
	String_Set(30,20,"Press Enter For Start!");
	String_Set(30,22,"ESC Button is quit.");
}

void Scene_DrawStop()
{
	String_Set(19, 2, "������������������������������������������������������");
	String_Set(19, 3, "��           Stop          ��");
	String_Set(19, 4, "������������������������������������������������������");
	String_Set(30, 20, "Press Enter For Restart!");
	String_Set(30, 22, "Q Button is quit.");
}

void Scene_DrawGameOver()
{
	String_Set(19, 2, "������������������������������������������������������");
	String_Set(19, 3, "��        Game Over        ��");
	String_Set(19, 4, "������������������������������������������������������");
	String_Set(30, 20, "Press Enter For Restart!");
	String_Set(30, 22, "ESC Button is quit.");
}

void Scene_DrawClear()
{
	String_Set(19, 2, "������������������������������������������������������");
	String_Set(19, 3, "��         Clear!!!        ��");
	String_Set(19, 4, "������������������������������������������������������");
	String_Set(30, 20, "Press Enter For Restart!");
	String_Set(30, 22, "ESC Button is quit.");
}