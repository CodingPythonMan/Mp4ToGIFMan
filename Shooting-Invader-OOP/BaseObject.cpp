#include "BaseObject.h"

BaseObject::BaseObject() : _X(0), _Y(0), _ObjectType(ObjectType::None)
{
}

BaseObject::~BaseObject()
{
}

bool BaseObject::CollisionCheck(BaseObject* targetObject)
{
	if (this->_X == targetObject->_X && this->_Y == targetObject->_Y)
		return true;

	return false;
}

ObjectType BaseObject::GetObjectType()
{
	return _ObjectType;
}