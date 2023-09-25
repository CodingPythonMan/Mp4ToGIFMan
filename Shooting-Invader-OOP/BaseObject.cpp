#include "BaseObject.h"

BaseObject::BaseObject() : _X(0), _Y(0), _ObjectType(0)
{

}

BaseObject::~BaseObject()
{

}

int BaseObject::GetObjectType()
{
	return _ObjectType;
}