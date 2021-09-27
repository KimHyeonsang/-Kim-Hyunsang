#pragma once
#include"Header.h"

class Scene
{	
public:
	virtual void Initalize()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	Scene();
	virtual ~Scene();
};

