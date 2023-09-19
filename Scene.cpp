#include "Scene.h"
#include "Render.h"

SceneType gSceneType = SceneType::TITLE;

void Scene_DrawTitle()
{
	String_Set(19,2,"忙式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	String_Set(19,3,"弛      Abyss Invader      弛");
	String_Set(19,4,"戌式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	String_Set(30,20,"Press Enter For Start!");
	String_Set(30,22,"ESC Button is quit.");
}

void Scene_DrawStop()
{
	String_Set(19, 2, "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	String_Set(19, 3, "弛           Stop          弛");
	String_Set(19, 4, "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	String_Set(30, 20, "Press Enter For Restart!");
	String_Set(30, 22, "Q Button is quit.");
}

void Scene_DrawGameOver()
{
	String_Set(19, 2, "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	String_Set(19, 3, "弛        Game Over        弛");
	String_Set(19, 4, "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	String_Set(30, 20, "Press Enter For Restart!");
	String_Set(30, 22, "ESC Button is quit.");
}

void Scene_DrawClear()
{
	String_Set(19, 2, "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	String_Set(19, 3, "弛         Clear!!!        弛");
	String_Set(19, 4, "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	String_Set(30, 20, "Press Enter For Restart!");
	String_Set(30, 22, "ESC Button is quit.");
}