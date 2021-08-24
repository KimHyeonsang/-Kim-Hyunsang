#pragma once
#include "Scene.h"

class Object;
class Logo : public Scene
{
private:
	Object* ObjectList[2];
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
};