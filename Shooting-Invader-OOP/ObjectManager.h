#pragma once
#include "MyList.h"
#include "BaseObject.h"

class ObjectManager
{
public:
	void Update();
	void Render();

	static ObjectManager* GetInstance(void)
	{
		static ObjectManager objectManager;
		return &objectManager;
	}

	void CreateObject(BaseObject* objectPtr);
	void DestroyObject(BaseObject* objectPtr);
	void AddDeleteList(BaseObject* objectPtr);
	void ClearList();

private:
	ObjectManager();
	~ObjectManager();

	MyList<BaseObject*> ObjectList;
	MyList<BaseObject*> DeleteList;
};