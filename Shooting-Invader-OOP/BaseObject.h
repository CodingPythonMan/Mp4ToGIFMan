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

	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void OnCollision(BaseObject* target) = 0;

	bool CollisionCheck(BaseObject* targetObject);
	ObjectType GetObjectType();

protected:
	int _X;
	int _Y;
	ObjectType _ObjectType;
};