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

	// 모든 Object 위치 업데이트를 먼저 한다.
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
			if ((*iter)->CollisionCheck(*target_iter))
			{
				(*iter)->OnCollision(*target_iter);
				(*target_iter)->OnCollision(*iter);
			}
		}
	}

	// 삭제 처리
	for (iter = DeleteList.begin(); iter != DeleteList.end(); ++iter)
	{
		DestroyObject(*iter);
	}
	DeleteList.clear();
}

void ObjectManager::Render()
{
	MyList<BaseObject*>::iterator iter;

	for (iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		(*iter)->Render();
	}
}

void ObjectManager::CreateObject(BaseObject* objectPtr)
{
	ObjectList.push_back(objectPtr);
}

void ObjectManager::DestroyObject(BaseObject* objectPtr)
{
	ObjectList.remove(objectPtr);
}

void ObjectManager::AddDeleteList(BaseObject* objectPtr)
{
	DeleteList.push_back(objectPtr);
}

void ObjectManager::ClearList()
{
	ObjectList.clear();
	DeleteList.clear();
}