#pragma once
#include "Scene.h"

class Object;
class Menu : public Scene
{
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Menu();
	virtual ~Menu();
};