#pragma once
class SceneBase
{
public:
	virtual int Update() = 0;
	virtual void Render() = 0;
};