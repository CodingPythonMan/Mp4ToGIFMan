#pragma once

class BaseObject
{
public:
	BaseObject();
	virtual ~BaseObject();

	virtual bool Update() = 0;
	virtual void Render() = 0;

	int GetObjectType();

protected:

	int _X;
	int _Y;
	int _ObjectType;
};