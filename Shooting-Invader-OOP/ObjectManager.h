#pragma once
#include "MyList.h"
#include "BaseObject.h"

class ObjectManager
{
public:
	void Update();
	void Render();
	void CreateObject();

	static ObjectManager* GetInstance(void)
	{
		static ObjectManager objectManager;
		return &objectManager;
	}

private:
	ObjectManager();
	~ObjectManager();

	MyList<BaseObject*> ObjectList;
};