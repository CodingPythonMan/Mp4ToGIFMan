#pragma once

enum class ObjectType {
	None,
	Missile,
	Monster,
	Player
};

class BaseObject
{
public:
	BaseObject();
	virtual ~BaseObject();

	virtual bool Update() = 0;
	virtual void Render() = 0;
	virtual void OnCollision() = 0;

	bool CollisionCheck(BaseObject* object, BaseObject* targetObject);
	ObjectType GetObjectType();

protected:
	int _X;
	int _Y;
	ObjectType _ObjectType;
};