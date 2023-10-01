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

	template<typename T>
	void CreateObject(T objectPtr)
	{
		ObjectList.push_back(objectPtr);
	}

	template<typename T>
	void DestroyObject(T objectPtr)
	{
		ObjectList.remove(objectPtr);
	}

private:
	ObjectManager();
	~ObjectManager();

	MyList<BaseObject*> ObjectList;
};