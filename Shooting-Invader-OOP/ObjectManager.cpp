#include "ObjectManager.h"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::Update()
{
	MyList<BaseObject*>::iterator iter;

	// 모든 Object 위치 업데이트 후, 충돌처리
	for (iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		(*iter)->Update();
	}

	// 충돌 처리
	for (iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		MyList<BaseObject*>::iterator target_iter = iter;
		for (++target_iter; target_iter != ObjectList.end(); ++target_iter)
		{
			
		}
	}
}

void ObjectManager::Render()
{
	MyList<BaseObject*>::iterator iter;

	for (iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		(*iter)->Render();
	}
}