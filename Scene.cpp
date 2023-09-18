#include "Scene.h"
#include "Render.h"

SceneType gSceneType = SceneType::TITLE;

void DrawTitle()
{
	String_Set(19,2,"忙式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	String_Set(19,3,"弛      Abyss Invader      弛");
	String_Set(19,4,"戌式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	String_Set(30,20,"Press Any Button For Start!");
	String_Set(30,22,"ESC Button is quit.");
}