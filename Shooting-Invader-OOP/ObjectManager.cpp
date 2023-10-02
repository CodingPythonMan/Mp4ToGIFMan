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

	// ��� Object ��ġ ������Ʈ ��, �浹ó��
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