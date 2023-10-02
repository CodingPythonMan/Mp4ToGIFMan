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

	// ��� Object ��ġ ������Ʈ�� ���� �Ѵ�.
	for (iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		(*iter)->Update();
	}

	// �浹 ó��
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

	// ���� ó��
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