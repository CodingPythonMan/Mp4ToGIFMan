#include "Scene.h"
#include "Render.h"

SceneType gSceneType = SceneType::TITLE;

void DrawTitle()
{
	String_Set(19,2,"������������������������������������������������������");
	String_Set(19,3,"��      Abyss Invader      ��");
	String_Set(19,4,"������������������������������������������������������");
	String_Set(30,20,"Press Any Button For Start!");
	String_Set(30,22,"ESC Button is quit.");
}